#!/bin/bash
# AIM: To accept the name of a file from the user and create it in the same directory
read -p "Enter the name of the file that you wish to create: " filename
touch $filename
echo "The file $filename has been created in the current working directory."
