# !/bin/bash
# AIM: To extract recprds and store them in separate files
det=`cat students.dat`
n=`wc -l students.dat`
for ((i=1;i<=n;i++))
do
	line=`$det | head -n+i | tail -n1`
	filename=`echo $line | cut -d "|" -f2`+".dat"
	touch $filename
	echo "Name: `echo $line | cut -d '|' -f2`" > filename 
	echo "Roll Number: `echo $line | cut -d '|' -f2`" >> filename
	echo "Phone Number: `echo $line | cut -d '|' -f2`" >> filename
done