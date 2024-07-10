#!/bin/bash
# This script is used to organize files in a directory

# Check if the directory exists
if [ ! -d $1 ]; then
    echo "Directory does not exist"
    exit 1
fi

# Change to the directory
cd $1

# Create directories for different file types
mkdir -p images documents others

# Move files to their respective directories
for file in *; do
    case $file in
        *.jpg|*.png|*.gif)
            mv $file ./images
            ;;
        *.doc|*.pdf|*.txt)
            mv $file ./documents
            ;;
        # Move all other files to the others directory
        if [ -f $file ]; then      
            mv $file ./others
        fi
    esac
done

echo "Files organized successfully"



