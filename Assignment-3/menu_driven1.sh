#!/bin/bash
echo -e "Enter your choice:\n1. Show the permissions of a file or directory.\n2. Show the number of files and directories under the current directory separately.\n3. Show the last modification time of a file in current directory.\n4. Exit from Menu."
while [ 1 ]
do
	read -p "Enter your choice: " choice
	case $choice in
		1) read -p "Enter the name of the file: " filename
		   if [ -e $filename ]
		   then 
			echo "File Permissions are as follows: `ls -l $filename | cut -c 2-10`"
		   fi
		   ;;
		2) directories=`ls -l | cut -d " " -f1 | grep "^d" | wc -l`
		   files=`ls -l | cut -d " " -f1 | grep "-" | wc -l`
		   echo "The number of Directories is $directories"
		   echo "The number of Files is $files"
		   ;;
		3) read -p "Enter the name of the file: " fname
		   mod_time=`ls -l | cut -b 40-45`
		   echo "The last access time is : $mod_time"
		   ;;
		4) echo "Exiting"
		   exit
		   ;;
		*) echo "Invalid Choice...Try Again"
	esac
done