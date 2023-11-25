#!/bin/awk
# AIM: to print specific fields
BEGIN {FS="|"; print("Here we will print certain fields only")}
{print $1,"->",$3}
END {printf("The required fields have been displayed.\n")}
