#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sharad T");
MODULE_DESCRIPTION("driver with module param");
MODULE_VERSION("0.1");

static char *name = "world";
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name,"name to display");

static int  __init st_init(void){
   printk(KERN_INFO "name provided: %s \n", name);
   return 0;
}


static void __exit st_exit(void) {
    printk(KERN_INFO "goodbye kern \n", name);
}

module_init(st_init);
module_exit(st_exit);
