#!/bin/bash

SEC_DIR="~/myDirectory/secondDirectory"
FIRST_DIR="~/myDirectory"
mkdir ~/myDirectory
mkdir ~/myDirectory/secondDirectory
touch ~/myDirectory/secondDirectory/myNotePaper.txt
cp ~/myDirectory/secondDirectory/myNotePaper.txt ~/myDirectory
mv ~/myDirectory/myNotePaper.txt myOldNotePaper.txt
