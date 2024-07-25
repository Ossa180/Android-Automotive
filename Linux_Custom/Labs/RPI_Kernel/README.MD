# RPI + Kernel Lab
---

- git clone —depth=1 https://github.com/raspberrypi/linux.git
- cd linux
- choose RPI3 configs

```markdown
make bcm2835_defconfig ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-  
```

- increase opened file descriptor

```markdown
ulimit -n 8192
```

- choose cross tool , arch

```markdown
sudo apt install gcc-arm-linux-gnueabihf
```

```markdown
export ARCH=arm 
export CROSS_COMPILE=arm-linux-gnueabihf-
make menuconfig 
# Enable devtmpfs
	> Device Drivers > Generic Driver Option Maintain a devtmpfs filesystem to mount at /dev
# CONFIG_BLK_DEV_INITRD to support initramfs
	> General setup                                                                                                                                                                                │  
  -> Initial RAM filesystem and RAM disk (initramfs/initrd) support (BLK_DEV_INITRD [=y])
```

- Compile kernel, modules and DTBs :

```markdown
make -j$(nproc) zImage modules dtbs ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-
# $nproc  no of viratual cores to use
```

- install modules

```markdown
export INSTALL_MOD_PATH=/home/eng-tera/linux/
make modules_install ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-
# make >> take all source and turn to binary files beside its own files
```

- Copy to SD Card

```markdown
cp arch/arm/boot/zImage /media/boot
cp arch/arm/boot/dts/broadcom/bcm2710-rpi-3-b.dtb /media/boot
cp arch/arm/boot/dts/overlays/disable-bt.dtbo /media/boot/overlays
```

- Or Boot from TFTP Server

Copy zImage and device tree binary to the TFTP server:

```
cp linux/arch/arm/boot/zImage /srv/tftp/
```

# **Creating the Root File System**

Set up the root filesystem by copying BusyBox binaries:

```markdown
# to go out from busybox directory
cd ..

# create directory rootfs
mkdir rootfs

# copy the content inside the _install into rootfs
cp -rp ./busybox/_install/ ./rootfs
		# rp to change permission

# change directory to rootfs
cd rootfs

mkdir proc
mkdir sys
mkdir dev
mkdir etc

# change rootfs owner to be root
sudo chown -R root:root *
		# root owner cuz when creating i have no users

# Create config directory:
mkdir etc/init.d
touch etc/init.d/rcS
chmod +x etc/init.d/rcS

```

## Create **`/etc/init.d/rcS`** startup script

```markdown
#!/bin/sh

# mount a filesystem of type `proc` to /proc
mount -t proc nodev /proc

# mount a filesystem of type `sysfs` to /sys
mount -t sysfs nodev /sys

# mount -t devtmpfs none /dev
exec /bin/sh
```

# **Creating initramfs**

```markdown
#  make sure do not includes kernel modules in the initramfs as it will take much space.
cd ~/rootfs
# archive and compress all commands binaries
find . | cpio -H newc -ov --owner root:root > ../initramfs.cpio
cd ..
gzip initramfs.cpio
mkimage -A arm -O linux -T ramdisk -d initramfs.cpio.gz uRamdisk

			# libraries the kernel need it in case of dynamic lib
cp -r /home/eng-tera/linux/lib/ /home/eng-tera/rootfs/
			# pi linux repo
```

# **Booting with initramfs**

Copy uRamdisk you created earlier in this section to the boot partition on the microSD card, and then use it to boot to point that you get a U-Boot prompt. Then enter these commands:

```markdown
# make sure the variable initramfs doesn't overwrite the dtb and zimage variables
setenv initramfs [chose a value depends on bdinfo] # empty value far from kernel addr

setenv initramfs_addr 0x30000000
setenv kernel_addr_r 0x8000
setenv fdt_addr_r 0x10000

fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r bcm2710-rpi-3-b.dtb
fatload mmc 0:1 $initramfs uRamdisk
setenv bootargs console=ttyS0,115200 root=/dev/ram0 init=/linuxrc

bootz $kernel_addr_r $initramfs $fdt_addr
```
