#!/bin/awk -f
BEGIN { FS="~"
	highest_marks=0
}
{
	score=($3+$4+$5)
	if(score>highest_marks) {
		highest_marks=score
		student=$1
	}
}
END {
	print "The student with the highest marks is " student
}
