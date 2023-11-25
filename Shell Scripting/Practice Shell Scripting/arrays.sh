# !/bin/bash
# AIM: to perform basic operations on arrays
read -a arr -p "Enter the elements of the array: "
echo "The elements of the array (before sorting) is as follows: ${arr[*]}"
n=${#arr[*]}
for((i=0;i<n-1;i++))
	for((j=$i+1;j<n;j++))
		if [ arr[i] -gt arr[j] ]
			t=arr[i]
			arr[i]=arr[j]
			arr[j]=t
echo "The elements of the sorted array is as follows: ${arr[*]}"
