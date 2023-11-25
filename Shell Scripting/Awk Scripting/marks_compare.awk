BEGIN {FS="~"}
$NF>20 && NR>1 {print $1}
