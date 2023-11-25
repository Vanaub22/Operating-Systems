BEGIN {FS="~"}
NR>1 {print $NF}
