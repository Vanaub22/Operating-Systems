#!/bin/bash
# AIM: to find the number of valid filenames in the current directory passed as CLAs
cnt=0
for filename in $*
do
	if [ -f $filename ]
	then
		echo "$filename is a valid file name in the current directory."
		cnt=$((cnt+1))
	else
		echo "$filename is not a valid filename in the current directory."
	fi
done
echo "The total number of valid file names passed as command-line arguments = $cnt"
