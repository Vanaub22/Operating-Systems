#/bin/bash
# To find the sum of digits of a user-input number
read -p "Enter a whole number: " x
if (( x<0 ))
	then
	echo "The number is negative. Invalid input."
else
	num=$x
	sum=0
	while (( num>0 ))
		do
			(( sum=$sum+($num%10) ))
			(( num=$num/10 ))
		done
	echo "The sum of digits of $x is $sum"
fi
