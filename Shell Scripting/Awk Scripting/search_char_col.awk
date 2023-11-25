BEGIN {IGNORECASE=1}
NR>1 &&  $1~/m/{print $0}
