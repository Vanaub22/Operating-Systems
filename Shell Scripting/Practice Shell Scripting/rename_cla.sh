#!/bin/bash
# AIM: to rename a file where the current name and the new name will be passed as Command Line Arguments
echo -n "Here is the initial content of the directory: "
ls
mv $1 $2
echo "The file $1 has been renamed to $2 in the current directory."
echo -n "The contents of the directory now, are as follows: "
ls
