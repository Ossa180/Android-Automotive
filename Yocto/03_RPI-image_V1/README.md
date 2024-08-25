# meta-raspi

- clone meta-raspi kirkstone

```markdown
cd /poky
git clone https://github.com/agherzan/meta-raspberrypi.git
```

![image.png](meta-raspi%206755c1a5733749958ad539b90c38c5be/image.png)

- create new build enironemnt

```markdown
source oe-init-build-env build-rpi
```

- make sure i am in correct branch

```markdown
# to know which branch
git branch
# to switch
git checkout kirkstone
```

![image.png](meta-raspi%206755c1a5733749958ad539b90c38c5be/image%201.png)

- add meta-raspi to bblayers `/poky/build-rpi/conf`
- vim bblayers.conf

![image.png](meta-raspi%206755c1a5733749958ad539b90c38c5be/image%202.png)

![image.png](meta-raspi%206755c1a5733749958ad539b90c38c5be/image%203.png)

- to create our customized DISTRO , it must be under `/layer/conf/distro/mydistro.con`

![image.png](meta-raspi%206755c1a5733749958ad539b90c38c5be/image%204.png)

- inside distro.conf

```markdown
# intead of copy the poky conf
require conf/distro/poky.conf

DISTRO = "mohamedRPI-distro"
DISTRO_VERSION= "1.0"
DISTRO_NAME= "mohamed Distro version_1"
MAINTAINER = "Mohamed Hussein"
```

> require >> if not found it will PANIC
include >> if not found it will continoue building
> 

- in local.conf change DISTRO >> almaza

---

---

### Machine

- to know the machine of Raspberry >> `/poky/conf/machine/`

![image.png](meta-raspi%206755c1a5733749958ad539b90c38c5be/image%205.png)

### Image

- inside /meta-myraspi/recipes-core/images/myrecipe-minimal.bb
- NOTE: IMAGE_FEATURES : wriiten in [recipe.bb](http://recipe.bb) , EXTRA_IMAGE_FEATURES : wriiten in local.conf
- create myrecipe-minimal.bb

- in `Local.conf`

![image.png](meta-raspi%206755c1a5733749958ad539b90c38c5be/image%206.png)

```markdown
MACHINE = "raspberrypi3-64"
```

```markdown
# in local . conf
IMAGE_FSTYPES = "tar.xz ext4 rpi-sdimg" 
BB_NUMBER_THREADS ?= "8"
PARALLEL_MAKE ?= "-j 8"
# in Distro Features
DISTRO_FEATURES:append = " systemd"
VIRTUAL-RUNTIME_init_manager = "systemd"
VIRTUAL-RUNTIME_initscripts = ""

# in image Features
# add dropbear to the image
IMAGE_INSTALL:append = " dropbear systemd systemd-serialgetty"
# UNABLE UART
ENABLE_UART = "1"

```

- After building

![image.png](meta-raspi%206755c1a5733749958ad539b90c38c5be/image%207.png)

- Copy the image to SD card to flash on RPI

```java
sudo dd if=core-image-sato-raspberrypi3-64.rpi-sdimg of=/dev/sdb bs=1M

```

- Connect UART

```java
sudo picocom -b 115200 /dev/ttyUSB0
```

- Connect Ethernet cable between my machine and RPI
- check Ethernet ip

```java
ifconfig
```

- Connect SSH

```java
sudo ssh root@192.168.1.7
```