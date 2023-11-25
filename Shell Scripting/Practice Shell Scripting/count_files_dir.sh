# !/bin/bash
# AIM: to print the number of files in the current directory
echo "The contents of the current directory are as follows:"
ls
echo -n "The number of files in the current directory is: "
ls -l | grep "^-r" | wc -l
echo -n "The number of directories under the current directory is: "
ls -l | grep "^d" | wc -l
