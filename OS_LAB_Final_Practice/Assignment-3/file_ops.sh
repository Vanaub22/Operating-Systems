#!/bin/bash
# To:
# i) Show the permissions of a file or directory; 
# ii) Show the number of files and directories under current directory separately; 
# iii) Show the last modification time of a file in current directory;
# iv) Exit from menu.
while [ 1 ]
do
	read -p "Enter your choice: " choice
	case $choice in
	1)
	read -p "Enter the name of the file: " filename
	if [ -e $filename ]
	then
		permissions=`ls -l | grep "$filename" | cut -c2-10`
		echo "The permissions granted to $filename are: $permissions"
	else
		echo "$filename is not a file under the current directory"
	fi
	;;
	2)
	files=`ls -l | grep "^-" | wc -l`
	directories=`ls -l | grep "^d" | wc -l`
	echo "The number of files under the current directory `pwd` is $files."
	echo "The number of directories under the current directory `pwd` is $directories."
	;;
	3)	
	read -p "Enter the name of the file: " filename
	if [ -e $filename ]
	then
		modtime=`ls -l | grep "$filename" | cut -c42-47`
		echo "The last modification time of the file $filename is $modtime"
	else
		echo "$filename is not a file under the current directory"
	fi
	;;
	4)
	echo "Exiting..."
	exit
	;;
	*)
	echo "Invalid Choice...Try Again"
	esac

done
