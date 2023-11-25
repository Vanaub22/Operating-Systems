#!/bin/bash
# To find the common logarithm of a user-input number (passed via command-line)
echo -n "The common logarithm of $1 is: "
echo "scale=5; l($1)/l(10)" | bc -l
