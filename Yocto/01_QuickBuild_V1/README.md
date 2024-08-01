# Yocto V.1  Quick Build

# Yocto Project Quick Build Based on Kirkstone

### Prepare Environment

- [https://docs.yoctoproject.org/4.0.20/ref-manual/system-requirements.html](https://docs.yoctoproject.org/4.0.20/ref-manual/system-requirements.html)


- Requeired Package for Host Machine ( `UBUNTU` )

```markdown
sudo apt install gawk wget git diffstat unzip texinfo gcc build-essential chrpath socat cpio python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 python3-subunit zstd liblz4-tool file locales libacl1
sudo locale-gen en_US.UTF-8
```

---

---

### Choose Yocto Release  `Pocky-Kirkstone`

- clone Pocky repo Kirkstone branch

![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled.png)

```markdown
# clone poky.
git clone -b kirkstone https://github.com/yoctoproject/poky.git
# switch directory.
cd poky
```

![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled%201.png)

- check branch

```markdown
git log
```

![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled%202.png)

---

---

### Test Environment using QEMU

- Source build script

```markdown
source oe-init-build-env
# it will go automatic to new directory called build
# can change dir name when sourcing by provide a name at last of command
```

![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled%203.png)

- Edit `local.conf` file
    1. search for `MACHINE` ??=   and choose the target
    2. append a variable for CPU cores to build
    
    ```markdown
    # Number of threads.
    BB_NUMBER_THREADS="8"
    PARALLEL_MAKE="-j 8"
    # to know max number of threads
    nproc
    # or
    lscpu
    ```
    
    ![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled%204.png)
    

- Now lets Bake our image

```markdown
# build image.
bitbake core-image-minimal
```

![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled%205.png)

![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled%206.png)

- we can see number of running task don’t exceed `8` , which is number of threads we were given before

![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled%207.png)

- now we done

![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled%208.png)

- run QEMU

```markdown

runqemu <MACHINE> # runqemu qemux86-64 nographic
```

![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled%209.png)

- now we logged in as a root , with no password

![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled%2010.png)

- to exit

```markdown
poweroff
```

![Untitled](Yocto%20V%201%20Quick%20Build%2084431d67321a492e8519491fc07cf32f/Untitled%2011.png)
