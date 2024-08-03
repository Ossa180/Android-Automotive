# Simple Module

# Create a simple module and test it.

---

1. Must know which kernel version i am working on

```markdown
uname -r
# 6.5.0-44-generic
```

- each version has its own build system
1. my build system exist in `/usr/src/linux-headers-6.5.0-44-generic/`

1. driver are writtend in C , beside the driver there is a MAKEFILE about how to build it (static or dynamic)

![Untitled](Simple%20Module%2081bc1a77390d42658560cd1d0e81ac93/Untitled.png)

1. Invoke build system to build the driver

```markdown
# invoke using this command
make M=/path/to/directory modules
# the directory that contain the makefile and the C source code
```

> M >> to specify the directory of external module
> 
- **NOTE**: must be inside UBUNTU buildsystem directory

### OR

- in `/mydriver_v1/`
    - make a C source code file
    
    ```c
    #include <linux/module.h>
    #include <linux/fs.h>
    #include <linux/init.h>
    #include <linux/cdev.h>
    
    /*Init Function*/
    static int __init mykernel_init(void)
    {
        printk(KERN_INFO "hello from kernel device driver \n");
        return 0;
    }
    
    /*DeInit Function*/
    static void __exit mykernel_exit(void)
    {
        printk(KERN_INFO "bye bye mr.Kernel \n");
    }
    
    /* Macro ptr to function*/
    module_init(mykernel_init);
    module_exit(mykernel_exit);
    
    // MODULE INFO SECTION //
    MODULE_LICENSE("GPL");
    MODULE_AUTHOR("Mohamed");
    MODULE_DESCRIPTION("A simple hello world driver");
    ```
    
    - then a Makefile to build the source file
    
    ```makefile
    obj-m += mydriver.o # obj-m to build Dynamic
    
    KDIR = /lib/modules/$(shell uname -r)/build
    
    all:
    	make -C $(KDIR) M=$(PWD) modules
    
    clean:
    	make -C $(KDIR) M=$(PWD) clean
    ```
    

---

- then build the file

```markdown
make
```

![Untitled](Simple%20Module%2081bc1a77390d42658560cd1d0e81ac93/Untitled%201.png)

- now add the Driver to our modules

```markdown
sudo insmod mydriver.ko
```

- check for dmesg

```markdown
sudo dmesg
```

![Untitled](Simple%20Module%2081bc1a77390d42658560cd1d0e81ac93/Untitled%202.png)

- now remove the module

```markdown
sudo rmmod mydriver
```

![Untitled](Simple%20Module%2081bc1a77390d42658560cd1d0e81ac93/Untitled%203.png)