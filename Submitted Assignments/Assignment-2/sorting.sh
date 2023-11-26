#!/bin/bash
echo -n "Enter the elements of the array separated by spaces: "
read -a arr
n=${#arr[*]}
echo "The array has a total of $n elements."
echo "The array elements are as follows: ${arr[*]}"
for((i=0;i<n-1;i++))
do
	smallest=${arr[$i]}
	idx=$i
	for((j=i+1;j<n;j++))
	do
		if((arr[j]<smallest))
		then
			smallest=${arr[$j]}
			idx=$j
		fi
	done
	temp=${arr[$i]}
	arr[i]=${arr[$idx]}
	arr[idx]=$temp
done
echo "The array after sorting is as follows: ${arr[*]}"
