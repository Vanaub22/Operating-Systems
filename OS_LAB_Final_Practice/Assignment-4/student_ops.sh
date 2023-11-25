#!/bin/bash
# Create a student file (Students.dat) containing four fields, Name, Roll, Phone and Address.
# The field separator is ‘|’.
# Now, write a menu driven script to do the following:
# (i) Sort the records in reverse order of Roll number and store the output in a new file (Sorted.dat).
# (ii) Replace lower case letters with the upper case letters in the file 'Sorted.dat'. Take file input using redirection.
# (iii) Write commands to find out the records with unique name in the file 'Sorted.dat'. Append the output records to 'Students.dat'.
# (iv) Display only the 2nd and 3rd lines from the above file (Students.dat).
while [ 1 ]
do
	read -p "Enter your choice: " choice
	case $choice in
	1)
	cat Students.dat | sort -t "|" -rk 2 > Sorted.dat
	echo "Operation Successful"
	;;
	2)
	output=`cat Sorted.dat | tr [:lower:] [:upper:]`
	echo "$output" > Sorted.dat
	echo "Operation Successful"
	;;
	3)
	names=`cat Sorted.dat | cut -d "|" -f1 | sort -u`
	echo "The unique records are:" >> Students.dat
	for name in $names
	do
		echo "`cat Sorted.dat | grep "$name"`" | head -1 >> Students.dat  
	done
	echo "Operation Successful"
	;;
	4)
	echo "The 2nd and 3rd lines are: "
	cat Students.dat | head -3 | tail -2
	;;
	5)
	echo "Exiting..."
	exit
	;;
	6) # Additional condition just for displaying and checking
	echo "This is the current state of the Students.dat file:"
	cat Students.dat
	echo "This is the current state of the Sorted.dat file:"
	cat Sorted.dat
	;;
	*)
	echo "Invalid choice...Try again"
	;;
	esac
done
