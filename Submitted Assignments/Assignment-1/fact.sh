#!/bin/bash
echo -n "Enter the number: "
read n
a=1
t=1
if [ $n -lt 0 ] 
then
	echo "Invalid Input"
else
	while [ $t -le $n ];
	do
	a=`expr $a \* $t`
	t=`expr $t + 1`
	done
	echo "The factorial of $n is $a."
fi