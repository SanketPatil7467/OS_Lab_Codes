#!/bin/bash
 
factorial_recursive() {
        	if [ $1 -le 1 ]; then
        	echo 1
        	else
        	a=$(( $1 - 1 ))
        	sub_factorial=$(factorial_recursive $a)
        	echo $(( $1 * sub_factorial ))
        	fi
}
 
factorial_non_recursive() {
        	num=$1
        	fact=1
 
        	while [ $num -gt 0 ]; do
        	fact=$(( $fact * $num ))
        	num=$(( $num - 1 ))
        	done
 
        	echo $fact
}
 
echo -n "Enter a number: "
read number
 
recursive_result=$(factorial_recursive $number)
echo "Factorial using recursion: $recursive_result"
 
non_recursive_result=$(factorial_non_recursive $number)
echo "Factorial using non-recursive: $non_recursive_result"

