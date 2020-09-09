#ifndef RSPI_INTERRUPT_H
#define RSPI_INTERRUPT_H

#include <linux/init.h> 
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/mutex.h>


#include <linux/gpio.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sharad Chandra T");
MODULE_DESCRIPTION("Interrupt handling in rasberrypi");
MODULE_VERSION("0.1");

static int rpi_led_open(struct inode *i, struct file *f);
static int rpi_led_release(struct inode *i, struct file *f);
static ssize_t rpi_led_read(struct file *f, char *buff, size_t len, loff_t *off);
static ssize_t rpi_led_write(struct file *f, const char * buff, size_t len, loff_t *off);
static irqreturn_t pushbtn_irq_handle(int irq ,  struct pt_regs *regs);
static int configure_gpio();

#define LED_ON 1
#define LED_OFF 1
#define NUM_OF_DEVICES 2
#define BASE_NUM  0
#define CHAR_DEV_NAME "led_rpi_gpio"
#define DEV_NAME "led_rpi"
//#define DEV_NAME_1 "led2"

//Initialize GPIO values
//GPIO numbers

// Input:   3.3V GPIO
#define GPIO_IN   17
#define GPIO_GND   
#define GPIO_OUT  11



#endif
