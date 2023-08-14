#!/bin/bash
echo -e "Menu:\n1) Accept personal details along with password and store them in a data file\n2) Display the personal details after successfully matching the password stored in the file\n3) EXIT"
while [ 1 ]
do
	read -p "Enter your choice: " choice
	case $choice in
	1) read -p "Enter name: " name
	   read -p "Enter password: " password
	   read -p "Enter Roll number: " roll
	   read -p "Enter your age: "  age
	   echo "$name;$password;$roll;$age;" >> personal.dat
	   ;;
	2) read -sp "Enter the password :" password
	   f=`cat personal.dat | grep $password`
	   if [[ $f = '' ]]
	   then
		echo "Password Incorrect."
	   else 
		echo
		name=`echo $f | cut -d ";" -f1`
		roll=`echo $f | cut -d ";" -f3`
		age=`echo $f | cut -d ";" -f4`
		echo "Name: $name Roll: $roll Age: $age"
	   fi
       ;;
	3) exit
	   ;;
	*) echo "Invalid Choice...Try Again"
	   ;;
	esac
done

	   
