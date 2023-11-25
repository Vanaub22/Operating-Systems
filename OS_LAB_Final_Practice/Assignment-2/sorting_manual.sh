#!/bin/bash
# To sort numbers using any well-known sorting algorithm
echo -n "Enter array elements separated by spaces: "
read -a arr
echo "The elements in the array are: ${arr[*]}" > output.txt
# Will be performing Selection Sort
n=${#arr[@]}
for((i=0;i<n-1;i++)) do
	for((j=i+1;j<n;j++)) do
		if((arr[i]>arr[j]))
		then
			tmp=${arr[i]}
			arr[i]=${arr[j]}
			arr[j]=$tmp
		fi
	done
done
echo "The array after sorting is as follows: ${arr[@]}" >> output.txt
