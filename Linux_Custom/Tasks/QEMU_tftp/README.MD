# Using TFTP-hpa
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

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/e6d02fce-f9fb-49b0-8412-b5d0f350fe90/2cfe102f-d8d1-49c9-8351-10bf4d278c26/Untitled.png)

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

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/e6d02fce-f9fb-49b0-8412-b5d0f350fe90/fcadd9df-bc31-4a48-88fa-724ede0adcc8/Untitled.png)
