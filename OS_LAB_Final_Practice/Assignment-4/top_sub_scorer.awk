#!/bin/awk -f
BEGIN { FS="~" }
NR>1 {
	if(highest1<$3) {
		highest1=$3
		highest1_name=$1
	}
	if(highest2<$4) {
		highest2=$4
		highest2_name=$1
	}
	if(highest3<$5) {
		highest3=$5
		highest3_name=$1
	}
}
END {
	print "The highest scorer in Subject-1 is " highest1_name " with a score of " highest1
	print "The highest scorer in Subject-2 is " highest2_name " with a score of " highest2
	print "The highest scorer in Subject-3 is " highest3_name " with a score of " highest3
}
