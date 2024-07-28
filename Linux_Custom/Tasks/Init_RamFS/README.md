# InitRamfs

# **Initial RAM filesystem**

---

- make dir

```markdown
mkdir initRamfs
```

- copy our file system into directory

```markdown
/initramfs$ sudo cp -rp /home/mohamed/SD/ROOTFS/* .

```

- make sure root is the owner

```markdown
 sudo chown -R root:root *
```

![Untitled](InitRamfs%20638760e383044bca9bff1c067d8481df/Untitled.png)

- create cpio archive

```markdown
find . | cpio -H newc -ov --owner root:root > ../initramfs.cpio
```

![Untitled](InitRamfs%20638760e383044bca9bff1c067d8481df/Untitled%201.png)

![Untitled](InitRamfs%20638760e383044bca9bff1c067d8481df/Untitled%202.png)

- compress the archived files

```markdown
cd .. 
gzip initramfs.cpio
```

![Untitled](InitRamfs%20638760e383044bca9bff1c067d8481df/Untitled%203.png)

- make image

```markdown
 mkimage -A arm -O linux -T ramdisk -d initramfs.cpio.gz myRAMfs
```

![Untitled](InitRamfs%20638760e383044bca9bff1c067d8481df/Untitled%204.png)

- Copy image to SD/BOOT

```markdown
sudo cp myRAMfs /home/mohamed/SD/BOOT/
```

- run QEMU

```markdown
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -kernel u-boot -sd ~/Desktop/iti_android/Linux_labs/SD_Card/sd.img 
```

- set environment

```markdown
setenv initRamfs_addr 0x60700000
fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
fatload mmc 0:1 $initRamfs_addr myRAMfs
setenv bootargs console=ttyAMA0 rdinit=/bin/sh

saveenv
bootz $kernel_addr_r $initRamfs_addr $fdt_addr_r
```

![Untitled](InitRamfs%20638760e383044bca9bff1c067d8481df/Untitled%205.png)