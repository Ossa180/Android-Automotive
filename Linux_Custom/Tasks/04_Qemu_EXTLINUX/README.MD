# EXTLINUX

# **boot the QEMU via The extlinux.conf and the bootflow scan command**

- make directory inside BOOT (FAT16) partition and create file inside it

![Untitled](EXTLINUX%20ce161ebe8de140c68c8e01025669c479/Untitled.png)

- inside the file write this script

![Untitled](EXTLINUX%20ce161ebe8de140c68c8e01025669c479/Untitled%201.png)

- in qemu

- old bootcmd

![Untitled](EXTLINUX%20ce161ebe8de140c68c8e01025669c479/Untitled%202.png)

- edit bootcmd

```markdown
setenv bootcmd bootflow scan
saveenv
```

![Untitled](EXTLINUX%20ce161ebe8de140c68c8e01025669c479/Untitled%203.png)

- the output is normal bec. the image is grabage
