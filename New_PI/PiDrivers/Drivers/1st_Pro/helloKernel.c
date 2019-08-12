#include <linux/module.h> /* Needed by all modules */

#include <linux/kernel.h> /* Needed for KERN_ALERT */

MODULE_LICENSE("GPL");    /* Setting Licence to GPL */

int __init ourinitmodule(void) /* Will be called during insmod <module>.ko */
{

    printk(KERN_ALERT "\n Welcome to sample kernel module.... \n");

    return 0;
}

void __exit ourcleanupmodule(void) /* Will be called during rmmod <module> */{
    printk(KERN_ALERT "\n Thanks....Exiting. \n");
    return;
}
/* Macros for init and cleanup module */
module_init(ourinitmodule);
module_exit(ourcleanupmodule);
