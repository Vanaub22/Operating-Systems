#!/bin/bash
# AIM: to pass two directory names and create a directory name with the second name if the first directory is not found
if [ -d $1 ]
then
	echo "The directory $1 is present in the current directory"
else
	mkdir $2
	echo -e "The directory $1 was not present in the current directory.\nA directory named $2 has now been created."
fi
