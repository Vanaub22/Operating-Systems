#!/bin/bash
# To print the Fibonacci series upto n (user-input) terms
read -p "Enter the value of n: " n
if ((n<=0))
	then
	echo -n "Value of n is lesser than 1. Invalid Input."
else
	a=0
	b=1
	echo -n "The first $n terms of the Fibonacci series are as follows: 1 "
	for ((i=1;i<n;i++)) do
		((term=a+b))
		echo -n "$term "
		((a=b))
		((b=term))
		done
fi
echo ""
