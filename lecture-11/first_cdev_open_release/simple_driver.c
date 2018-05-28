#include "linux/kernel.h"
#include "linux/module.h"
#include "linux/init.h"
#include "linux/cdev.h"
#include "linux/kdev_t.h"
#include "linux/fs.h"
MODULE_AUTHOR("mxl");
MODULE_DESCRIPTION("this is a simple driver");
MODULE_VERSION("2018-1-8");
MODULE_LICENSE("GPL");
int i ;
module_param(i,int,S_IRUGO);
struct cdev mydev;
int major = 100,minor = 1;// 
dev_t dev ;

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
struct file_operations myops=
{
	.owner = THIS_MODULE,
	.open  = myopen,
	.release = myclose,
};
static int __init myinit(void)
{
	int ret;
	i ++;
	mydev.owner = THIS_MODULE;
	dev =  MKDEV(major,minor) ;//( (major & 0xFFF) << 20 ) | minor & 0xFFFFF;
	ret =register_chrdev_region(dev,1,"hello");
	if(ret < 0)
	{
        alloc_chrdev_region(&dev,1,1,"hello");
		major = MAJOR(dev);
		minor = MINOR(dev);
	}
    printk(KERN_INFO "major = %d,minor = %d\n",major,minor);
	cdev_init(&mydev,&myops);//mydev.ops = &myops;
	cdev_add(&mydev,dev,1);//mydev.dev = dev;
	//mydev.ops = &myops;
	printk(KERN_INFO "myinit function exec, i = %d\n",i);
	return 0;
}
static void __exit myexit(void)
{
	cdev_del(&mydev);
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO "myexit function exec\n");
	return ;
}
module_init(myinit);
module_exit(myexit);
