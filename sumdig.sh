#!/bin/bash
echo -n "Enter a number: "
read num
copy=$num
if [ $num -lt 0 ] 
then
	echo "Invalid Input"
else
	sum=0
	while [ $num -gt 0 ];
	do
		dig=`expr $num % 10`
		sum=`expr $sum + $dig`
		num=`expr $num / 10`	
	done
	echo "The sum of digits of $copy = $sum"
fi