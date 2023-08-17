#!/bin/bash
# AIM: to check if the current user is the root user
user=$(whoami)
if [ user = "root" ]
then
	echo "You are the root user."
else
	echo "You are a regular user."
fi
