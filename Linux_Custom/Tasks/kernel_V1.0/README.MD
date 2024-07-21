# Kernel Customization V1.0
---

- clone kernel

```markdown
git clone --depth=1 git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git
# depth 1  >> last release only
cd linux
```

- Set Cross compiler

```markdown
export CROSS_COMPILE=~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-
```

- search for my Arch

```markdown
arch/arm/configs
ls | grep vexpress
<vexpress_defconfig>
```

![Untitled](https://github.com/Ossa180/Embedded_Linux/blob/main/Linux_Custom/Tasks/kernel_V1.0/Untitled.png)

- config vexpress

```markdown
make vexpress_defconfig
```

![Untitled](https://github.com/Ossa180/Embedded_Linux/blob/main/Linux_Custom/Tasks/kernel_V1.0/Untitled%201.png)

- to solve this error we must change the Path of searching
set Archtecture type

```markdown
export ARCH=arm
```

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/e6d02fce-f9fb-49b0-8412-b5d0f350fe90/2d785879-8328-4405-acf1-52b681349499/Untitled.png)

- configurations

```markdown
make menuconfig
```

---

## Menu Configs

- Disable devtmpfs ( we will enable it later)
    - >>  Device drivers >> Generic driver option >>  automount devtmpfs
- make Kernel Compression to XZ ( smaller size >> fast booting kernel )
    - >> general setup >> kernel compression mode >>  XZ
- Kernel Release [ Optional [
    - append username after booting kernel
    
    ![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/e6d02fce-f9fb-49b0-8412-b5d0f350fe90/71db6a05-806d-4cc4-a532-a41b4bbb372a/Untitled.png)
    

---

- now build

```markdown
make -j4 zImage modules dtbs
```

- **`j4`:** This option specifies the number of parallel jobs to run during the build process,`j4` indicates that the build system should use 4 parallel jobs to speed up the compilation. Using multiple jobs in parallel can significantly reduce the time it takes to build the kernel.

> Note that : each core can do 2 job, and in my case my Computer has 4 cores (2 cores do the build job and the other 2 cores for the linux OS). This command to know your cores number
> 

```markdown
lscpu
```

- **`zImage`:** This is a compressed Linux kernel image (`zImage`). The `zImage` is the core executable that gets loaded into memory by the bootloader.
- **`modules`:** This target instructs the build system to compile loadable kernel modules. Kernel modules are pieces of code that can be dynamically loaded into or unloaded from the kernel, providing additional functionality.
- **`dtbs`:** This target instructs the build system to build the device tree blobs (DTBs). Device tree is a data structure that describes the hardware board.

---

- in case of error <gmp.h>

```markdown
sudo apt-get install libgmp-dev
```

- in case of error <mpc.h>

```markdown
sudo apt-get install libmpc-dev
```

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/e6d02fce-f9fb-49b0-8412-b5d0f350fe90/39758c8d-1e40-447c-b003-deda2c52423e/Untitled.png)
