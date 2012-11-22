#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/delay.h>

void my_tasklet(unsigned long data)
{
	while(1) {
		printk(KERN_INFO "running tasklet\n");
		udelay(10000);
	}

}

static __init int modinit(void)
{
	DECLARE_TASKLET(mytask, my_tasklet, 10);
	printk(KERN_INFO"Hello World!\n");
	return 0;
}

static __exit void modexit(void)
{

}

module_init(modinit);
module_exit(modexit);
