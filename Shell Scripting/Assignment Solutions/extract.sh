# !/bin/bash
# AIM: to extract details from a file and store it in another file
read -p "Enter the name: " name
line="`grep $name students.dat`"
echo "Name: `echo $line | cut -d "|" -f1`" > details.dat
echo "Roll Number: `echo $line | cut -d "|" -f2`" >> details.dat
echo "Phone Number: `echo $line | cut -d "|" -f3`" >> details.dats