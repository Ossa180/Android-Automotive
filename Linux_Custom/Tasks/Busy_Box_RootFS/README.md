# Organized busyBox SD Card

- **Download Busy Box**

```markdown
git clone https://github.com/mirror/busybox.git
```

- **Configure your Cross-Compiler and the Target Architecture**

```markdown
## Make Sure its in the same Terminal i will build and run qemu in it ##

export CROSS_COMPILE=~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-

export ARCH=arm
```

- Configuration

```markdown
make menuconfig
```

1. select **Linking Type in the build process (Static)**
    1. >> Setting >>scroll down to build option >> build static library
    
- build

```markdown
make
```

- I`n case of error`
- CONFIG_TC=n   , then make

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled.png)

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%201.png)

- Generate binaries of the rootfs

```markdown
make install
```

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%202.png)

> `The above message remember you to change the owner of the binary files to be owned by **root`**
> 

- Let's check who is the files owner

```markdown
ls -l _install/
## we will change the ownership later ##
```

---

---

- **Create Root File System (rootfs) for Embedded Linux Target**
    
    I will Create a Directory called "rootfs_Static" in my home directory to prepare my `rootfs` and then copy it to the *ext4* (partition2) in Virtual SD card.
    

```markdown
cd ~
mkdir rootfs_Static
```

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%203.png)

- Copy the Content of `~/busybox/_install` to `rootfs_Static` by unsing "*cp* or *rsync*"

```markdown
sudo rsync -av ~/Desktop/iti_android/Busybox/busybox/_install/* ~/rootfs_static
```

> the `rsync` command with the specified options is used to copy the contents of the `_install` directory (inside the `busybox` directory) to the `rootfs_Static` directory, preserving various attributes of the files and directories in the process.
> 

> `rsync`: used for file and directory synchronization or copying with synchronization.
> 

> `av`: Options passed to `rsync`:
> 

> `a` (archive mode): This option is a shortcut that combines several options, including `r` (recursive), `l` (preserve symbolic links), `p` (preserve permissions), `t` (preserve modification times), and others. It helps in maintaining the properties of the files and directories during the synchronization.
> 

> `v` (verbose): This option increases the verbosity of the output, providing more details about the files being copied.
> 

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%204.png)

---

- In `root_Static` Directory, create the other root directories manually

```markdown
mkdir boot dev etc home mnt proc root srv sys
```

- Create a startup script called `rcS` in `etc/init.d/` to do initialization tasks when booting the kernel

```
mkdir etc/init.d
touch etc/init.d/rcS
```

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%205.png)

- Open `rcS` file and write the following commands then **change its permission to make it executable** :

```
vim etc/init.d/rcS
```

```markdown
#!/bin/sh
# mount a filesystem of type `proc` to /proc
mount -t proc nodev /proc
# mount a filesystem of type `sysfs` to /sys
mount -t sysfs nodev /sys
# mount devtmpfs if you forget to configure it in Kernel menuconfig
#there is two options uncomment one of them  
#option1: mount -t devtmpfs devtempfs /dev
#option2: mdev -s
mount -t devtmpfs devtempfs /dev

## Note: if didn't mount devtmpfs , may error in TTYAMA0 ##Create a Configuration file called inittab in etc directory

touch etc/inittab

```

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%206.png)

- now lets change script permission

```markdown
sudo chmod +x etc/init.d/rcS
```

- Create a Configuration file called `inittab` in `etc` directory

```markdown
touch etc/inittab
```

```markdown
# inittab file 
#-------------------------------------------------------
#When system startup,will execute "rcS" script
::sysinit:/etc/init.d/rcS
#Start"askfirst" shell on the console (Ask the user firslty to press any key) 
ttyAMA0::askfirst:-/bin/sh
#when restarting the init process,will execute "init" 
::restart:/sbin/init
```

> These entries are part of the configuration that dictates the behavior of the init process. The inittab file is read and interpreted by the init process to determine what actions to take in initialization.
> 
> - **Entry** : refers to a line or a rule that defines a particular action to be taken during the system's boot process.
> 1. `::sysinit:/etc/init.d/rcS`
> - This line specifies that when the system is initializing (referred to as "sysinit"), it should execute the script `/etc/init.d/rcS`. The `::` indicates that no particular terminal or user is associated with this entry ( applies to all terminals and users).
> 1. `ttyAMA0::askfirst:-/bin/sh`
> - This line associates the terminal `ttyAMA0` with the "askfirst" action. When the system encounters this terminal, it will prompt the user before starting the `/bin/sh` shell. If the user agrees, the shell is started. The `` before the shell path indicates that the shell should replace the specified terminal in case it exits.
> 1. `::restart:/sbin/init`
> - This line indicates what should happen when the init process is restarted. It specifies that the `/sbin/init` process should be started. This is a common practice to ensure that if the init process is somehow terminated or restarted, it will bring the system back to the initial state.

- change permission of the file rootfs_static

```markdown
ls -lh ~/rootfs_static
```

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%207.png)

```markdown
sudo chown -R root:root ~/rootfs_static
```

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%208.png)

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%209.png)

---

---

- Mount SD card

```markdown
sudo mount -o rw /dev/loop22p2 /home/mohamed/SD/ROOTFS
```

> `-o rw`: This option specifies that the filesystem should be mounted with read-write permissions. It stands for "read-write."
> 

- Copy the content of `~/rootfs_static` to the mounted media

```markdown
sudo cp -rp ~/rootfs_static/* /home/mohamed/SD/ROOTFS
```

> 
> 
> - `r`: Recursively copy directories and their contents.
> - `p`: Preserve the ownership, permissions, and timestamps of the original files.
> 
> ![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%2010.png)
> 

---

- make sure Kernel (zImage) and vexpress.dtb in the BOOT partition

- Open Qemu

```markdown
qemu-system-arm -M vexpress-a9 -m 128M -nographic -kernel path/u-boot -sd path/sd.img
```

```markdown
qemu-system-arm -M vexpress-a9 -m 128M -nographic -kernel u-boot -sd ~/Desktop/iti_android/Linux_labs/SD_Card/sd.img

```

- **Set U-boot Environment variables**

```markdown
setenv bootargs 'console=ttyAMA0 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait init=/sbin/init' 
```

> 
> 
> - **`console=ttyAMA0`:** Specifies the console device. It's set to the serial port (`ttyAMA0`).
> - **`root=/dev/mmcblk0p2`:** Specifies the root filesystem's block device. It indicates that the root filesystem is located on the SD card partition 2 (`/dev/mmcblk0p2`).
> - **`rootfstype=ext4`:** Specifies the filesystem type of the root filesystem, it's set to ext4.
> - **`rw`:** Indicates that the root filesystem should be mounted as read-write.
> - **`rootwait`:** Causes the kernel to wait for the root device to become available before proceeding with the boot process.
> - **`init=/sbin/init`:** Specifies the path to the init process, which is the first process started by the Linux kernel.

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%2011.png)

---

- specify address of kernel and dtb file

```markdown
setenv kernel_addr_r 0x60000000

setenv fdt_addr_r 0x65000000

saveenv
```

- Load zImage and dtb from SD card

```markdown
fatload mmc 0:1 $kernel_addr_r zImage

fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
# md $kernel_addr_r to check
```

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%2012.png)

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%2013.png)

- Boot kernel

```markdown
bootz $kernel_addr_r - $fdt_addr_r

```

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%2014.png)

- And Done Conragtulation We have our Own Image

![Untitled](Organized%20busyBox%20SD%20Card%2087afdc010e3243c8abe1851cf18a1a36/Untitled%2015.png)