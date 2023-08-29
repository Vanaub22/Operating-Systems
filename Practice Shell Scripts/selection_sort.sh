# !/bin/bash
# AIM: to perform selection sort on user-input array
echo -n "Enter the elements of the array: "
read -a arr
echo "The elements of the user-input are as follows: ${arr[*]}"
echo "The number of elements in the user-input array are as follows: ${#arr[*]}"
n=${#arr[*]}
for((i=0;i<n-1;i++)); do
	for((j=i+1;j<n;j++)); do
		if [ ${arr[i]} -gt ${arr[j]} ]; then
			t=${arr[i]}
			arr[i]=${arr[j]}
			arr[j]=$t
		fi
	done
done
echo "The contents of the array after sorting are as follows: ${arr[*]}"
