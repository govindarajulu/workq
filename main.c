#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/delay.h>

void my_tasklet(unsigned long data)
{
	//while(1) {
		printk(KERN_INFO "running tasklet\n");
	//	udelay(10000);
	//}
		return;

}
unsigned long int data=100;
DECLARE_TASKLET(mytask, my_tasklet, &data);
static __init int modinit(void)
{

	printk(KERN_INFO"Hello World!\n");
	//tasklet_init(&mytask,my_tasklet, &data);
	//tasklet_enable(&mytask);
	tasklet_schedule(&mytask);
	return 0;
}

static __exit void modexit(void)
{
	tasklet_kill(&mytask);
}

module_init(modinit);
module_exit(modexit);
