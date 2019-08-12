#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x425785a6, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xbf8c4e93, __VMLINUX_SYMBOL_STR(class_unregister) },
	{ 0xf20dabd8, __VMLINUX_SYMBOL_STR(free_irq) },
	{ 0xb0000374, __VMLINUX_SYMBOL_STR(gpiod_unexport) },
	{ 0xfe990052, __VMLINUX_SYMBOL_STR(gpio_free) },
	{ 0x9545af6d, __VMLINUX_SYMBOL_STR(tasklet_init) },
	{ 0x72106bb8, __VMLINUX_SYMBOL_STR(gpiod_direction_output_raw) },
	{ 0xd6b8e852, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0x402e6d43, __VMLINUX_SYMBOL_STR(gpiod_to_irq) },
	{ 0x5c2b435b, __VMLINUX_SYMBOL_STR(gpiod_export) },
	{ 0xbea8798b, __VMLINUX_SYMBOL_STR(gpiod_direction_input) },
	{ 0x47229b5c, __VMLINUX_SYMBOL_STR(gpio_request) },
	{ 0x8531f886, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x9cd9fd20, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x191148f8, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x89ba0ccf, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x718833ea, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x1d137244, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xd1069d72, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x1770d8e, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x8abc5994, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xfaef0ed, __VMLINUX_SYMBOL_STR(__tasklet_schedule) },
	{ 0xca54fee, __VMLINUX_SYMBOL_STR(_test_and_set_bit) },
	{ 0xb2d48a2e, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0xe4a48145, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0xd0ef25d2, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x72eee54b, __VMLINUX_SYMBOL_STR(gpiod_set_raw_value) },
	{ 0xc0409705, __VMLINUX_SYMBOL_STR(gpio_to_desc) },
	{ 0xf4fa543b, __VMLINUX_SYMBOL_STR(arm_copy_to_user) },
	{ 0x97255bdf, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "E29B2497973D0A1BC04790C");
