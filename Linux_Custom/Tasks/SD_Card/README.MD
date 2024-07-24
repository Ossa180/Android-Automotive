# SD Card Task for making SD Card with 2 Partitions


### Block Device  (SD CARD)

- dd if=/dev/zero   of=sd.img bs=1M count=1024
    - if  >> input file
    - of >>
    - bs  >> block size per clock
    - count >> until reach 1024 time
- cfdisk sd.img
    - cfdisk create parition table
    - select label type (dos)
    - new >> part 200 mb >>>  primary (dos ) (MBR) >> bootable (FAT16) >> write>>yes >> quit
        - if we cat the file it will display meta data
- loop device  >> contibute with normal file as block storage
    - sudo losetup -f   -- show - -partscan sd.img
        - -partscan to see the HEADER (meta data)
        - -f  find empty loop
- to inject file system algo
    - mkfs.vfat -F 16 -n BOOT /dev/loop13p1
        - name first partition “boot”
        - -f 16  >> fat16
        - -n name
        - ls /dev/loop
        - now the algorithm in sd card
- sudo mkfs.ext4 -L ROOT /dev/loop17p2
    - -L  for label
- to check if correct
    - lsblk -f /dev/loop17p1
- if i deleted the file it will be soft format >> i can recover it again
- sudo losetup -d /dev/loop
    - -d detach
    - still have access , can read and write

# for easy use later us SCRIPT
```markdown
#!/bin/bash

echo "making SD card Partition ..."
~/Desktop/iti_android/Linux_labs/SD_Card
var=$(sudo losetup -f --show --partscan ~/Desktop/iti_android/Linux_labs/SD_Card/sd.img)
sudo mount ${var}p1 /media/mohamed/BOOT
sudo mount ${var}p2 /media/mohamed/ROOT

echo "SD card mounted at ${var} "
```
