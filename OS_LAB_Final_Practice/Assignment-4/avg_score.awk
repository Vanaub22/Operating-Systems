#!/bin/awk -f
BEGIN { 
	FS="~"
}
NR>1 {
	avg=($3+$4+$5)/(NF-2)
	print "The average score for " $1 " is " avg
}
