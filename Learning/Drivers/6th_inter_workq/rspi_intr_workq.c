#include "rspi_intr_workq.h"

int irq_num;
char kern_buf[500];
static short send_msg_len;
static dev_t dev_num;
struct class *sys_class;

struct gpio_led {
    struct device *sys_dev;
    struct cdev c_dev;
};


struct work_struct mywork;

static DEFINE_MUTEX(mymutex);

struct gpio_led *ctl_rpi[NUM_OF_DEVICES];
struct file_operations fops = 
{
     .owner   = THIS_MODULE,
     .open    =  rpi_led_open,
     .release =  rpi_led_release,
     .read    =  rpi_led_read,
     .write   =  rpi_led_write,
};

static int rpi_led_open(struct inode *i, struct file *f)
{
    printk(KERN_INFO CHAR_DEV_NAME": devic open");
    return 0;
}

static int rpi_led_release(struct inode *i, struct file *f)
{
    // mutex_unlock(&test_cdev_mutex);
    printk(KERN_INFO CHAR_DEV_NAME": devic release");
    return 0;
}


static ssize_t rpi_led_read(struct file *f, char *buff, size_t len, loff_t *off)
{
    int error_count = 0;
    error_count = copy_to_user(buff, kern_buf, send_msg_len);

    if (error_count==0)
    {            // if true then have success
      printk(KERN_INFO CHAR_DEV_NAME": Sent %d characters to the user\n", send_msg_len);
      return (send_msg_len=0);  // clear the position to the start and return 0
    }
    else {
      printk(KERN_INFO CHAR_DEV_NAME": Failed to send %d characters to the user\n", error_count);
      return -EFAULT;              // Failed -- return a bad address message (i.e. -14)
    }
}

static ssize_t rpi_led_write(struct file *f, const char * buff, size_t len, loff_t *off)
{
    //copy_from_user(kern_buf, buff, sizeof(kern_buf));
   sprintf(kern_buf, "%s(%zu letters)", buff, len);   // appending received string with its length
   send_msg_len = strlen(kern_buf);                 // store the length of the stored message
   printk(KERN_INFO CHAR_DEV_NAME": Received %zu characters from the user\n", len);
   return len;
}

static int led_set =0;


static void my_workq(struct work_struct *work)
{
  printk(KERN_INFO "######## IN WORK_QUEUE");
  mutex_lock(&mymutex); 
  int i =0;
  for ( i =0; i <10; i++ )
  {
    gpio_set_value(GPIO_OUT, led_set);
    msleep(100);
    led_set = !led_set;
  }
  mutex_unlock(&mymutex); 
}

//  static int last_interrupt_time =0;
//irqreturn_t pushbtn_irq_handle(int irq , void *data,  struct pt_regs *regs)
irqreturn_t pushbtn_irq_handle(int irq , void *data)
{
  printk(KERN_INFO "######## Irq handle");
  schedule_work( &mywork );
  return IRQ_HANDLED;
}

static int configure_gpio(void)
{
  int err = 0 ;
  err = gpio_request(GPIO_IN, CHAR_DEV_NAME);
  if(err < 0)
    return err;
  gpio_direction_input(GPIO_IN);
  gpio_export(GPIO_IN, false);
  irq_num = gpio_to_irq(GPIO_IN);
  err = request_irq(irq_num,  pushbtn_irq_handle, IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING , CHAR_DEV_NAME, NULL );
  if(err < 0)
    return err;

  err = gpio_request(GPIO_OUT, CHAR_DEV_NAME);
  if(err < 0)
    return err;
  gpio_direction_output(GPIO_OUT, LED_ON);
  gpio_export(GPIO_OUT, false);

  return err;
}


static int __init ledmodule_init(void) 
{
  int ret = 0, i =0;
  int Major = 0;
  int Minor = 0;

  if(alloc_chrdev_region(&dev_num, BASE_NUM, NUM_OF_DEVICES, CHAR_DEV_NAME) < 0 )   
  {
      printk(KERN_ERR "Major number allocation is failed for device "CHAR_DEV_NAME"\n");
      return -1;
  }

  Major = MAJOR(dev_num);
  Minor = MINOR(dev_num);

  printk(KERN_INFO "The major number for "CHAR_DEV_NAME" is %d",Major);

  sys_class = class_create(THIS_MODULE, CHAR_DEV_NAME);
  if(!sys_class) {
    printk(KERN_INFO  CHAR_DEV_NAME":unable to create class");
    unregister_chrdev_region(dev_num, NUM_OF_DEVICES);
    return -1;
  } 

  for ( i = 0; i < NUM_OF_DEVICES ; i++ ) { 

    ctl_rpi[i] = kmalloc(sizeof(struct gpio_led), GFP_KERNEL);
    cdev_init(&ctl_rpi[i]->c_dev, &fops); 
    if( cdev_add( &ctl_rpi[i]->c_dev, (dev_num+i),1)) {
      printk(KERN_INFO  CHAR_DEV_NAME":unable to add cdev");
      for ( i = 0; i < NUM_OF_DEVICES ; i++ ) {
        device_destroy(sys_class,  MKDEV(Major, Minor+i));
      }
      class_destroy(sys_class);
      unregister_chrdev_region(dev_num, NUM_OF_DEVICES);
      return ret;
    }

    ctl_rpi[i]->sys_dev = device_create(sys_class, NULL, 
                    (dev_num+i), NULL, DEV_NAME"%d",i);

    if(!ctl_rpi[i]->sys_dev) {
      printk(KERN_INFO  CHAR_DEV_NAME":unable to register class device_create");
      //class_unregister(sys_class);
      class_destroy(sys_class);
      cdev_del(&ctl_rpi[i]->c_dev);
      unregister_chrdev_region(dev_num, NUM_OF_DEVICES);
      return -1;
    } 
  }

  ret = configure_gpio();
  if(ret < 0){
    printk(KERN_INFO "Failed to configure GPIOs");
  }

  INIT_WORK(&mywork, my_workq);
  printk(KERN_INFO "Registered char driver "CHAR_DEV_NAME"");
  return ret;
}


static void  __exit ledmodule_exit(void) 
{
  int  i =0;
  //Free GPIOs
  gpio_set_value(GPIO_OUT, 0);
  gpio_free(GPIO_OUT);
  gpio_unexport(GPIO_OUT);

  gpio_free(GPIO_IN);
  gpio_unexport(GPIO_IN);
  free_irq(irq_num, NULL);

  //Destroy device and class
  device_destroy(sys_class, dev_num);
  class_unregister(sys_class);
  class_destroy(sys_class);
  for ( i = 0; i < NUM_OF_DEVICES ; i++ ) { 
    cdev_del(&ctl_rpi[i]->c_dev);
  }
    unregister_chrdev_region(dev_num, NUM_OF_DEVICES);
    printk(KERN_INFO "goodbye kern \n", CHAR_DEV_NAME);
}

module_init(ledmodule_init);
module_exit(ledmodule_exit);
