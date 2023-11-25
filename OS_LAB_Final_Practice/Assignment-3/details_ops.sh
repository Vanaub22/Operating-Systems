#!/bin/bash
# Write a menu driven shell script with three options:
# 1) Accept your personal details along with a password and store them in a data file (e.g. personal.dat);
# 2) Display the personal details stored in the data file after successfully matching the password stored in the file;
# 3) Exit from menu.
while [ 1 ]
do
	read -p "Enter your choice: " choice
	case $choice in
	1)
	read -p "Enter your name, roll and department separated by spaces: " name roll dept
	read -sp "Enter your PASSWORD: " password
	entry="$name|$roll|$dept|$password"
	echo "$entry" >> personal.dat
	echo "Your details have been added successfully"
	;;
	2)
	read -sp "Enter your PASSWORD: " password
	entry=`cat personal.dat | grep "$password"`
	if [ entry == "" ]
	then 
		echo "Password does not match with any of the entries...Try Again"
	else
		echo "Password verified successfully. Your details are as follows: "
		name=`echo "$entry" | cut -d "|" -f1`
		roll=`echo "$entry" | cut -d "|" -f2`
		dept=`echo "$entry" | cut -d "|" -f3`
		password=`echo "$entry" | cut -d "|" -f4`
		echo -e "Name: $name\nDepartment: $dept\nRoll Number: $roll"
	fi
	;;
	3)
	echo "Exiting..."
	exit
	;;
	*)
	echo "Invalid Choice..Try Again"
	;;
	esac
done
