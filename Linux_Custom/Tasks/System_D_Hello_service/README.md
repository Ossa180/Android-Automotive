# System-D Hello service

- make C code to print hello world

![Untitled](System-D%20Hello%20service%201c35eb192cb14a1aad1c43036e982aa6/Untitled.png)

- Compile the C code

```markdown
gcc app.c -o hello_system_D
sudo cp hello_system_D /bin
```

![Untitled](System-D%20Hello%20service%201c35eb192cb14a1aad1c43036e982aa6/Untitled%201.png)

---

- make service at `/etc/systemd/system`

```markdown
cd /etc/systemd/system
vim hello_service.service
```

```markdown
[Unit]
Description=hello service
[Service]
Type=simple
WorkingDirectory=/bin
ExecStart=hello_system_D
Restart=on-success
RestartSec=3
[Install]
WantedBy=muti-user.target
                     
```

![Untitled](System-D%20Hello%20service%201c35eb192cb14a1aad1c43036e982aa6/Untitled%202.png)

- Reload system-D to recognize new service

```markdown
sudo systemctl daemon-reload
```

- enable and start service

```markdown
sudo systemctl enable hello_service.service
sudo systemctl start hello_service.service
sudo systemctl status hello_service.service
sudo systemctl stop hello_service.service
```

- enable

![Untitled](System-D%20Hello%20service%201c35eb192cb14a1aad1c43036e982aa6/Untitled%203.png)

- status

![Untitled](System-D%20Hello%20service%201c35eb192cb14a1aad1c43036e982aa6/Untitled%204.png)

- start

![Untitled](System-D%20Hello%20service%201c35eb192cb14a1aad1c43036e982aa6/Untitled%205.png)

### Check logs

```markdown
journalctl -u hello_service.service -f
```

![Untitled](System-D%20Hello%20service%201c35eb192cb14a1aad1c43036e982aa6/Untitled%206.png)

- stop service