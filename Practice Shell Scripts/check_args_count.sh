#!/bin/bash
# AIM: to check if the number of command-line arguments is greater than 5 or not
if [ $# -gt 5 ]
then
	echo "The number of arguments ($#) is greater than 5."
else
	echo "The number of arguments ($#) is lesser than or equal to 5."
fi
