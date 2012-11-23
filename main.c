#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/workqueue.h>

MODULE_LICENSE("GPL");

void my_tasklet(unsigned long data)
{
	int i=100;
	while(i > 0) {
		printk(KERN_INFO "running tasklet=%d\n",i);
		udelay(1000);
		i--;
	}
	return;

}
void my_wq_fun(void* i)
{
	printk(KERN_INFO "this is my wq function\n");
}

unsigned long int data=100;
DECLARE_TASKLET(mytask, my_tasklet, &data);

struct workqueue_struct *my_wq;
struct work_struct *my_work_struct;
static __init int modinit(void)
{
	printk(KERN_INFO"Hello World!\n");
	my_wq = create_workqueue("goDgo's queue");
	if(!my_wq)
		return -1;
	my_work_struct = kmalloc(sizeof(struct work_struct),GFP_KERNEL);
	INIT_WORK(my_work_struct,my_wq_fun);
	queue_work(my_wq,my_work_struct);


	tasklet_schedule(&mytask);
	return 0;
}

static __exit void modexit(void)
{
	flush_workqueue(my_wq);
	destroy_workqueue(my_wq);
	tasklet_kill(&mytask);
}

module_init(modinit);
module_exit(modexit);
