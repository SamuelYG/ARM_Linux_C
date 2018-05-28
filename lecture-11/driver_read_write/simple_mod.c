#include "linux/module.h"
#include "linux/init.h"
#include "linux/kernel.h"
#include "linux/cdev.h"
#include "linux/kdev_t.h"
#include "linux/fs.h"
struct cdev  myuart;// owner struct file_operations *ops  dev_t dev
int myopen(struct inode *pnode,struct file *pfile)
{
	printk(KERN_INFO "myopen function exec\n");
	return 0;
}
int myclose(struct inode *pnode,struct file *pfile)
{
	printk(KERN_INFO "myclose function exec\n");
	return 0;
}
ssize_t mywrite (struct file *pfile, char __user *buf, size_t len, loff_t * plofft)
{
    printk(KERN_INFO "mywrite function exec\n");
	return 10;
}
//ssizt_t  int
ssize_t myread(struct file *pfile, char __user *buf, size_t len, loff_t * plofft)
{
	printk(KERN_INFO "myread function exec\n");
	return 100;
}
struct file_operations myops = 
{
	.open = myopen,
	.release = myclose,
	.write = mywrite,
	.read = myread,
};
int major = 100,minor = 1;
dev_t dev;
MODULE_LICENSE("GPL");
void mycdev_init(void)
{
	int ret;
	myuart.owner = THIS_MODULE;
	cdev_init(&myuart,&myops);//myuart.ops = &myops;
	dev = MKDEV(major,minor);
    ret = register_chrdev_region(dev,1,"simple_dev");
	if(ret < 0)
	{
		alloc_chrdev_region(&dev,1,1,"simple_dev");
		major = MAJOR(dev);
		minor = MINOR(dev);
	}
	printk(KERN_INFO "major = %d,minor = %d\n",major,minor);
	cdev_add(&myuart,dev,1);
    return ;
}
void mycdev_exit(void)
{
	cdev_del(&myuart);
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO "mycdev_exit exec\n");
}
static int __init myinit(void)
{
	mycdev_init();
	return 0;
}
static void __exit myexit(void)
{
	mycdev_exit();
    return ;
}
module_init(myinit);
module_exit(myexit);
