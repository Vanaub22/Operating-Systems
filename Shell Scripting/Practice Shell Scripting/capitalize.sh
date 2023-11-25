# !/bin/bash
# AIM: To capitalize the first letter of the name field
touch capitalized.dat
while read line;
do
	firstLetter=`echo "$line" | cut -c1 | tr [:lower:] [:upper:]`
	restOfLine=`echo "$line" | cut -c2-`
	echo "$firstLetter$restOfLine" >> capitalized.dat
done < students.dat
echo "The contents of the file after changes are: "
cat capitalized.dat
