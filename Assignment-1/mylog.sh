#!/bin/bash
N=$1
echo -n "Common log of $N = "
echo "scale=2; l($N)/l(10)" | bc -l