Create README.MD# Using TFTP-hpa
---

- install package

```markdown
sudo apt install tftpd-hpa
```

- this will create a System User Called tftp
    - this user will communicate
    
    ```markdown
    cat /etc/passwd | grep tftp
    ```
    
    - can;t login on this user

- tftp configuration

```markdown
sudo vim /etc/defaut/tftpd-hpa 
# then Append --create
# secure >> read
# create >> write permission
```

- restart service

```markdown
systemctl restart tftpd-hpa.service
```

- check Status

```markdown
systemctl status tftpd-hpa.service
```

- start service

```markdown
systemctl start tftpd-hpa.service
# or systemctl stop to stop 
```

- anyfile i want tp send must save it in /srv/tftp
![Untitled](https://github.com/Ossa180/Embedded_Linux/blob/main/Linux_Custom/Tasks/QEMU_tftp/files.png)


```markdown
# then change ownership
chown tftp:tftp tftp
```

---

### In Qemu

- to  load files in Uboot

```markdown
setenv serverip  <linux ip>
tftp $kernel_addr_r Zimage
```

![Untitled](https://github.com/Ossa180/Embedded_Linux/blob/main/Linux_Custom/Tasks/QEMU_tftp/tftp_done.png)
