#!/bin/bash
# To find the sum of all the integers passed as command line arguments
sum=0
for i in $*
do 
	((sum+=i)) 
done
echo "The sum of all the integers passed as command line arguments is $sum"
