# Organized BusyBox NFS

# **Network File System NFS**

---

> from previouse lessons , enable tap interface , move files to /srv/tftp  , use net nic in qemu
> 
1. install NFS

```
sudo apt install nfs-kernel-server
```

- Check If NFS Running

```
systemctl status nfs-kernel-server
```

![Untitled](Organized%20BusyBox%20NFS%2084d740d9fb4b48b6a502b9f06cd7165b/Untitled.png)

- check if the NFS server is listening on the default port (2049)

```markdown
ss -tulpen | grep 2049
```

![Untitled](Organized%20BusyBox%20NFS%2084d740d9fb4b48b6a502b9f06cd7165b/Untitled%201.png)

- install net-tool package

```
sudo apt install net-tools
```

- After installation, the **NFS server configuration** is stored in the `/etc/exports` file. This file will contain the exported directories which will be stored in the server (rootfs directory). In the beginning there is not exported directories. You can view **NFS configuration file** :

```markdown
 cat /etc/exports
```

![Untitled](Organized%20BusyBox%20NFS%2084d740d9fb4b48b6a502b9f06cd7165b/Untitled%202.png)

---

- Make a directory `/srv/nfs-share` which will be the Shareable Directory between the server (computer) and the client (target) .

```markdown
sudo mkdir /srv/nfs-share
```

- Copy Your **rootfs** in `/srv/nfs-share directory`

```markdown
sudo cp -rp /home/mohamed/SD/ROOTFS/* /srv/nfs-share
```

---

- make TAP port

```markdown
sudo ip tuntap add dev tap0 mode tap
sudo ip a add 192.168.2.8/24 dev tap0
sudo ip link set tap0 up
```

1. now ip address (server)

```
ifconfig
```

![Untitled](Organized%20BusyBox%20NFS%2084d740d9fb4b48b6a502b9f06cd7165b/Untitled%203.png)

> you can `PING` to make sure
> 
- Configure the NFS file /etc/exports by add this line inside the file :

```markdown
sudo vim /etc/exports
```

```markdown
# assumed ip for the Qemu
/srv/nfs-root 192.168.1.21(rw,no_root_squash,no_subtree_check)
# ping to make sure no device connected on it                                                                 
```

![Untitled](Organized%20BusyBox%20NFS%2084d740d9fb4b48b6a502b9f06cd7165b/Untitled%204.png)

![Untitled](Organized%20BusyBox%20NFS%2084d740d9fb4b48b6a502b9f06cd7165b/Untitled%205.png)

---

- Restart NFS

```markdown
sudo systemctl restart nfs-kernel-server
```

- open Qemu

```markdown
sudo qemu-system-arm -M vexpress-a9 -nographic -net nic -net tap,ifname=tap0,script=no -kernel ./u-boot -sd ~/Desktop/iti_android/Linux_labs/SD_Card/sd.img
```

- set environment

```markdown
setenv serverip 192.168.1.7
setenv ipaddr 192.168.1.1
setenv bootargs 'console=ttyAMA0  root=/dev/nfs ip=192.168.1.21:::::eth0 nfsroot=192.168.1.19:/srv/nfs-root,nfsvers=3,tcp rw init=/sbin/init'
saveenv
```

- check connection with server

```markdown
ping 192.168.1.20
ping $serverip
```

![Untitled](Organized%20BusyBox%20NFS%2084d740d9fb4b48b6a502b9f06cd7165b/Untitled%206.png)

- Load Kernel and DTB

```markdown
# make sure the files in /srv/tftp  with ownership tftp
tftp $kernel_addr_r zImage
tftp $fdt_addr_r vexpress-v2p-ca9.dtb
```

![Untitled](Organized%20BusyBox%20NFS%2084d740d9fb4b48b6a502b9f06cd7165b/Untitled%207.png)

![Untitled](Organized%20BusyBox%20NFS%2084d740d9fb4b48b6a502b9f06cd7165b/Untitled%208.png)