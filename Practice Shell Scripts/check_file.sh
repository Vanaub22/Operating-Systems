#!/bin/bash
# AIM: To  check if a file exists in the current directory and create the file if it doesn't exist
read -p "Enter the name of the file: " name
if [ -f $name ]
then 
	echo "The file $name exists in the current directory."
else
	touch $name
	echo "The file $name was not present initially in the current directory but has been created now."
fi
echo -n "List of files in the current directory is as follows: "
ls
