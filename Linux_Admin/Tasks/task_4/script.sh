#!/bin/bash

# Variables
USER_NAME="OSSA"
GROUP_NAME="iti"

# Check if group exists
if getent group $GROUP_NAME > /dev/null 2>&1; then
    echo "Group '$GROUP_NAME' already exists."
else
    # Create group
    echo "Creating group '$GROUP_NAME'."
    sudo groupadd $GROUP_NAME
fi

# Display group info
echo "Group Info:"
getent group $GROUP_NAME
echo ""

# Check if user exists
if id -u $USER_NAME > /dev/null 2>&1; then
    echo "User '$USER_NAME' already exists."
else
    # Create user and add to group
    echo "Creating user '$USER_NAME' and adding to group '$GROUP_NAME'."
    sudo useradd -m -g $GROUP_NAME $USER_NAME

fi


echo "User Info:"
id $USER_NAME
echo ""

# Display final group info
echo "Final Group Info:"
getent group $GROUP_NAME
echo ""
