# Yocto Custom Layer

Yocto QuickBuild-Custom layer

### Layers:

- Layers are directories that contain files about a category , store meta-data
- Layers Path are stored in `build/conf/bblayers.conf` at variable BBLAYERS
- to show current Layers that are seen

```markdown
bitbake-layers show-layers
```

---

---

# Create a new Layer

---

1. setup environment 

```markdown
source oe-init-build-env
```

1. create the layer

```markdown
bitbake-layers create-layer meta-mylayer1
```

![Untitled](Yocto%20Custom%20Layer%20e272bfb50ba3418fa5ccf83cf065bde6/Untitled.png)

- Note:: the layer must start with `meta-`
1. Add Layer to `bblayers.conf`
    - Method 1
    use Vim and edit `BBLAYERS` , append new meta **`PATH (Absulute)`**
    - Method 2
        
        use command
        
        ```markdown
        bitbake-layers add-layer <relative-path/meta-mylayer1>
        ```
        

![Untitled](Yocto%20Custom%20Layer%20e272bfb50ba3418fa5ccf83cf065bde6/Untitled%201.png)

![Untitled](Yocto%20Custom%20Layer%20e272bfb50ba3418fa5ccf83cf065bde6/Untitled%202.png)

---

---

1. Add Variable to **`meta-mylayer1/conf/layer.conf`**

![Untitled](Yocto%20Custom%20Layer%20e272bfb50ba3418fa5ccf83cf065bde6/Untitled%203.png)

---

### Note that all recipes must be under **`recipes-example`**

1. by defualt there is a file created in  **`meta-mylayer1/recipes-example/example/example_0.1.bb`**
if not exist its okay create it

![Untitled](Yocto%20Custom%20Layer%20e272bfb50ba3418fa5ccf83cf065bde6/Untitled%204.png)

- to run recipe

```markdown
bitbake example
```

![Untitled](Yocto%20Custom%20Layer%20e272bfb50ba3418fa5ccf83cf065bde6/Untitled%205.png)

- make directory for my recipes

```markdown
mkdir my_recipes
```

![Untitled](Yocto%20Custom%20Layer%20e272bfb50ba3418fa5ccf83cf065bde6/Untitled%206.png)

- create recipe file and must enter its version

```markdown
vim hello_recipe_1.0.bb
```

```markdown
DESCRIPTION = "Recipe created by lulu"
LICENSE = "MIT"

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  Welcome To Recipe By Mohamed Ahmed         *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");

    # Retrieve the value of the global variable
    # The d.getVar('MY_GLOBAL_VAR') function retrieves the value of the MY_GLOBAL_VAR variable.
    global_var = d.getVar('VAR')

    # Check the value of the global variable and print the corresponding message
    if global_var == "0":
        bb.plain("hi lulu")
    elif global_var == "1":
        bb.plain("hello ya lulu")
    else:
        bb.plain(f"Unknown value for MY_GLOBAL_VAR: {global_var}")

}

```

> python >> to define a python function   ,, `default is sh`
d.getVar()  >>  Get the value of the variable 'VAR' using d.getVar method
addtask   >> Adds the `display_banner` task to the task list, ensuring it runs before the                     
`do_compile` task. This integrates the custom Python function into the build process
> 

---

---

- now run recipe

```markdown
bitbake hello
```

![Untitled](Yocto%20Custom%20Layer%20e272bfb50ba3418fa5ccf83cf065bde6/Untitled%207.png)