#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>

static char *buf;

static void create_slub_error(void)
{
     buf = kmalloc(32, GFP_KERNEL);
     if (buf) {
           kfree(buf);
           printk("ben:access free memory\n");
           memset(buf, 0x55, 32);
     }
}


static int __init my_test_init(void)
{
	printk("benshushu: my module init\n");
	create_slub_error();
	return 0;
}
static void __exit my_test_exit(void)
{
	printk("goodbye\n");
}
MODULE_LICENSE("GPL");
module_init(my_test_init);
module_exit(my_test_exit);
