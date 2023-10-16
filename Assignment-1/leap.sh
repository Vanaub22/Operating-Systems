#!/bin/bash
echo -n "Enter the year: "
read y
if [ $y -le 0 ] 
then
	echo "Invalid Input"
elif [ `expr $y % 100` -eq 0 ] && [ `expr $y % 400` -eq 0 ]
then
	echo "This is a Leap Year"
elif [ `expr $y % 100` -eq 0 ] && [ `expr $y % 400` -ne 0 ]
then
	echo "This is not a leap year"
elif [ `expr $y % 4` -eq 0 ]
then
	echo "This is a leap year"
else
	echo "This is not a leap year"
fi