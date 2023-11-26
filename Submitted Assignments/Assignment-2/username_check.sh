#!/bin/bash
echo -n "Enter the username: "
read username
count="`grep -c $username /etc/passwd`"
if(($count==0))
then
	echo "$username is an Invalid Username."
else
	echo "$username is a Valid Username."
fi