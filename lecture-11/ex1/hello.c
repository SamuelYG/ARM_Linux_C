/*
 * hello.c
 *
 * Simple hello world 2.6 driver module with module_init, module_exit
 *
 * Copyright (C) 2005 Farsight
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
MODULE_LICENSE ("GPL");
static int  __init hello_2_init (void)
{
	int k;
	int j = 11;
	k = 10;
	k ++;
	printk (KERN_INFO "driver init,k = %d,j = %d\n",k,j);
	return 0;
}

static void  __exit hello_2_exit (void)
{
	int m = 13;
	m ++;
	printk (KERN_INFO "driver exit,m = %d\n",m);
}

module_init (hello_2_init);
module_exit (hello_2_exit);
