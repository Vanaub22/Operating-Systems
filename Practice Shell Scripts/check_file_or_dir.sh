#!/bin/bash
# AIM: to check if the name passed as CLA is that of a file, directory or none
if [ -f $1 ]
then
	echo "$1 is the name of a file in the current directory."
elif [ -d $1 ]
then
	echo "$1 is the name of a directory in the current directory."
else
	echo "$1 is neither a file nor a directory within the current directory."
fi
