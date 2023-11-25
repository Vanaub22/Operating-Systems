# !/bin/awk
# AIM: to print lines contaning a certain pattern using awk
BEGIN {printf("This awk script prints lines containing a specific pattern within a file\n")}
/(special)/{print}
END {printf("End of awk script\n")}