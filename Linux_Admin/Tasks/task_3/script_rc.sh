#!/bin/bash

if [ -f ~/.bashrc ]
then
	echo "bashrc exist in home dir"
	echo "export HELLO=$HOSTNAME" >> ~/.bashrc
	echo "export LOCAL=$(whoami)" >> ~/.bashrc
fi
echo "opening new terminal"
xterm &
