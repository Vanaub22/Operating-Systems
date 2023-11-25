#!/bin/bash
# To find if the user-input year is a leap year or not
read -p "Enter a year: " year
if [ `expr $year % 100` -eq 0 ] && [ `expr $year % 400` -eq 0 ]
	then
	echo "The number is divisible by 400 and 100"
elif [ `expr $year % 4` -eq 0 ] && [ `expr $year % 100` -ne 0 ]
	then
	echo "The number is divisible by 4"
else
	echo "It is not a leap year"
fi
