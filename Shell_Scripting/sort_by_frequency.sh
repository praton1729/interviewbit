
#! /bin/bash

#=========================================
#
#* File Name 	: sort_by_frequency.sh
#
#* Purpose 		: sorts and prints words with
#				  same freq on the same line
#
#* Creation Date : 21-09-2018
#
#* Last Modified : Mon 22 Dec 2008 10:36:49 PM PST
#
#* Created By 	: Prathu Baronia, 14D070046 
#
#==========================================

cat input | tr -s ' ' '\n' | sort | \
uniq -c | sort | tr -s '[:space:]' | \
awk -F' ' '$1==last {printf " %s",$2; next} NR>1 {print "";} {last=$1; printf "%s",$0;} END{print "";}' | \
sed "s/^[ \t]*//"
