#!/bin/bash
# AIM: to change the name of a file in the current directory.
echo -n "Here are the files in the current working directory: "
ls
read -p "Enter the current name of the file and the new name of the file that you wish to rename: " name new_name
mv $name $new_name
echo "The file $name in the current directory has been renamed to $new_name"
