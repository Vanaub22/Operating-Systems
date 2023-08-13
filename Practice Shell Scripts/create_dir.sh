#!/bin/bash
# AIM: to create 2 directories whose names will be passed by the user
read -p "Enter the names of the 2 directories separated by spaces: " dir1 dir2
mkdir $dir1 $dir2
echo "Two directories $dir1 and $dir2 have been created in the current working directory."
