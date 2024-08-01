# dual Boot

- create virtual sd card with three partitions

```markdown
dd if=/dev/zero of=sd.img bs=1M count=1024
cfdisk
losetup -f
mkfs
mount
```

![Untitled](dual%20Boot%2047a23b187a8747518f7e074b8467ee51/Untitled.png)

![Untitled](dual%20Boot%2047a23b187a8747518f7e074b8467ee51/Untitled%201.png)

![Untitled](dual%20Boot%2047a23b187a8747518f7e074b8467ee51/Untitled%202.png)

---

- Copy content to both roots

![Untitled](dual%20Boot%2047a23b187a8747518f7e074b8467ee51/Untitled%203.png)

- make script in `etc/init.d` of default root file system

```markdown
	sudo vim etc/init.d/root_mode
```

```markdown
#!/bin/sh

echo "LOADING ...."
echo "Welcome , Choose a root Filesystem you want to BOOT"
echo "1. SD card"
echo "2. Server"
read -p "enter [1/2]" choice

case $choice in
        1)
                echo "Loading RootFS from SD Card ... "
                mount /dev/mmcblk0p2 /mnt/root
                chroot /mnt/root /bin/sh
        ;;
        2)
                echo "Loading RootFS from Server Connecting ..."
                mount /dev/mmcblk0p3 /mnt/root
                chroot /mnt/root /bin/sh
        ;;
        *)
                echo "wrong root"
                echo "Load from DEFAULT SD card"
                mount /dev/mmcblk0p2 /mnt/rootsd
                chroot /mnt/root /bin/sh
        ;;
esac
```

![Untitled](dual%20Boot%2047a23b187a8747518f7e074b8467ee51/Untitled%204.png)

---

- edit inittab file

```markdown
::sysinit:/etc/init.d/rcS
::sysinit:/etc/init.d/root_mode.sh
ttyAMA0::askfirst:/bin/sh
::restart:/sbin/init
```

![Untitled](dual%20Boot%2047a23b187a8747518f7e074b8467ee51/Untitled%205.png)

- open Qemu

```markdown
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -kernel u-boot -sd ~/Desktop/iti_android/Linux_labs/SD_Card/sd3.img

```

- set env

```markdown
setenv bootargs 'console=ttyAMA0,115200 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait'
fatload mmc 0:1 ${kernel_addr_r} zImage
fatload mmc 0:1 ${fdt_addr_r} vexpress-v2p-ca9.dtb
saveenv
bootz $kernel_addr_r - $fdt_addr_r
```

![Untitled](dual%20Boot%2047a23b187a8747518f7e074b8467ee51/Untitled%206.png)