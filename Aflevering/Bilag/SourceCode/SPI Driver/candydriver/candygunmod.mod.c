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
	{ 0xf3c390b5, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x679344f8, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x16c549e4, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xfbc74f64, __VMLINUX_SYMBOL_STR(__copy_from_user) },
	{ 0x67c2fa54, __VMLINUX_SYMBOL_STR(__copy_to_user) },
	{ 0x5fb08567, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0xad71faa8, __VMLINUX_SYMBOL_STR(spi_setup) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x96cb78f4, __VMLINUX_SYMBOL_STR(driver_unregister) },
	{ 0xfc8af0ea, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x53c7ab95, __VMLINUX_SYMBOL_STR(spi_bus_type) },
	{ 0x9d2a998f, __VMLINUX_SYMBOL_STR(spi_sync) },
	{ 0xf1f8f312, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xf606617a, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x6a204038, __VMLINUX_SYMBOL_STR(spi_register_driver) },
	{ 0xec678710, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "A26B3574395E77E6404A737");
