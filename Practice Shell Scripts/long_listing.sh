#/bin/bash
# AIM: to print the long list of all the file names passed at command line (first check if file exists)
echo "The long listing of all the file names passed as command-line arguments are as follows: "
for filename in $*
do
	if [ -f $filename ] 
	then
		ls -l $filename
	else
		echo "There is no file named $filename in the current directory."
	fi
done
