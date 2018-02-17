#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sharad T");
MODULE_DESCRIPTION("driver with module param");
MODULE_VERSION("0.1");

static char *name = "world";
static char kern_buf[100] = "world is not enough";
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name,"first character device");

static dev_t dev_num; // Global variable for the first device number
static struct cdev c_dev; // Global variable for the character device structure
static struct class *cl; // Global variable for the device class
static struct device *dev_struct; // Global variable for the device class
static short send_msg_len;

#define NUM_COUNT 1
#define BASE_NUM  0
#define CHAR_DEV_NAME "test_cdev"

// The prototype functions for the character driver -- must come before the struct definition
static int     dev_open(struct inode *, struct file *);
static int     dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);



static int dev_open(struct inode *i, struct file *f)
{
    printk(KERN_INFO CHAR_DEV_NAME": devic open");
    return 0;
}
static int dev_release(struct inode *i, struct file *f)
{

    printk(KERN_INFO CHAR_DEV_NAME": devic release");
    return 0;
}
static ssize_t dev_read(struct file *f, char *buff, size_t len, loff_t *off)
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

static ssize_t dev_write(struct file *f, const char * buff, size_t len, loff_t *off)
{
    //copy_from_user(kern_buf, buff, sizeof(kern_buf));
   sprintf(kern_buf, "%s(%zu letters)", buff, len);   // appending received string with its length
   send_msg_len = strlen(kern_buf);                 // store the length of the stored message
   printk(KERN_INFO CHAR_DEV_NAME": Received %zu characters from the user\n", len);
   return len;
}

static struct file_operations fops =
{
   .owner = THIS_MODULE,
   .open = dev_open,
   .read = dev_read,
   .write = dev_write,
   .release = dev_release,
};

//struct device *device_create(struct class *cls, struct device *parent, dev_t devt, const char *fmt, ...)

static int  __init st_init(void)
{
   int ret, Major;

   if (alloc_chrdev_region(&dev_num, BASE_NUM, NUM_COUNT, CHAR_DEV_NAME) < 0)
   {
       printk(KERN_INFO "Major number allocation is failed for device "CHAR_DEV_NAME"\n");
       return -1;
   }

   Major = MAJOR(dev_num);
   printk(KERN_INFO "The major number for "CHAR_DEV_NAME" is %d",Major); 


   if (!(cl = class_create(THIS_MODULE, CHAR_DEV_NAME)))
   {
       printk(KERN_INFO  CHAR_DEV_NAME":unable to create class"); 
       unregister_chrdev_region(dev_num, CHAR_DEV_NAME);
       return NULL;
   }
   
   if( !(dev_struct = device_create(cl, NULL, dev_num, NULL, CHAR_DEV_NAME)))
   {
       class_destroy(cl);
       unregister_chrdev_region(dev_num, CHAR_DEV_NAME);
       printk(KERN_INFO  CHAR_DEV_NAME":unable to register class device_create"); 
       return NULL;
   }

   cdev_init(&c_dev, &fops);

   if ( (ret = cdev_add(&c_dev, dev_num, NUM_COUNT)) < 0 )
   {
       device_destroy(cl, dev_num);
       class_unregister(cl);
       class_destroy(cl);
       unregister_chrdev_region(dev_num, NUM_COUNT);
       return ret;
   }

   printk(KERN_INFO "name provided: %s \n", name);
   return 0;
}


static void __exit st_exit(void) 
{
    device_destroy(cl, dev_num);
    class_unregister(cl);
    class_destroy(cl);
    cdev_del(&c_dev);
    unregister_chrdev_region(dev_num, NUM_COUNT);
    printk(KERN_INFO "goodbye kern \n", name);
}

module_init(st_init);
module_exit(st_exit);
