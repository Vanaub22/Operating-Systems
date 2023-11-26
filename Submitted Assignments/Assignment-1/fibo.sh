#!/bin/bash
echo -n "Enter the number of terms: "
read n
if [ $n -lt 0 ]
	then
	echo "Invalid Input"
else
	a=0
	b=1
	echo -n "The Fibonacci Series upto $n terms is as follows: "
	for((i=0;i<n;i++))
	do
		echo -n "$a   "
		term=`expr $a + $b`
		a=$b
		b=$term
	done
	echo ""
fi