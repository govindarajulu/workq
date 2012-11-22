#include <linux/module.h>
#include <linux/kernel.h>

static __init int modinit(void)
{
	printk(KERN_INFO"Hello World!\n");
	return 0;
}

static __exit void modexit(void)
{

}

module_init(modinit);
module_exit(modexit);
