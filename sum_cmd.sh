#!/bin/bash
sum=0
for i in $*
do
	sum=`expr $sum + $i`
done
echo "The sum of all the numbers passed as CLAs = $sum"
