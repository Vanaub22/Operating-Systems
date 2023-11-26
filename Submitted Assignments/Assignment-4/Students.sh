#!/bin/bash
echo -e "MENU\n1. Sort records in reversed order and store in Sorted.dat.\n2. Replace lowercase letters with uppercase letters in Sorted.dat.\n3. Find records with unique names in Sorted.dat\n4. Display 2nd and 3rd ines from Students.dat.\n5. EXIT."
while [ 1 ]
do
	read -p "Enter your choice: " ch
	case $ch in
	1) sort -t "|" -rk 2 Students.dat > Sorted.dat
	echo "Sorting done. New file Sorted.dat created in the current directory."
	echo "Displaying the contents of the sorted file:"
	cat Sorted.dat
	;;
	2) tr [:lower:] [:upper:] < Sorted.dat > uppercase.dat
	echo "Lowercase converted to Uppercase."
	echo "The contents after conversion are as follows:"
	cat uppercase.dat
	;;
	3) echo "The unique names in Sorted.dat are as follows: " 
	echo "`uniq -u Sorted.dat`"
	;;
	4) echo "Displaying the 2nd and 3rd Lines from Students.dat:"
	cat Students.dat | head -n 3 | tail -n 2 
	;;
	5) echo "Execution Terminated." 
	exit
	;;
	*) echo "Invalid Input. Try Again."
	;;
esac
done
