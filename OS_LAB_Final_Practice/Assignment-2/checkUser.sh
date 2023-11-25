#!/bin/bash
# To check if username is valid
read -p "Enter username to be checked: " name
if [ "$(grep -c "^$name:" /etc/passwd)" -eq 0 ]
	then
	echo "$name is not a Valid Username." > output.txt
else
	echo "$name is a Valid Username." >> output.txt
fi
