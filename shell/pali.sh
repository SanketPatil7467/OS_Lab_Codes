#!/bin/bash
 
is_palindrome() {
    local str="$1"
    local reversed=""
    local length=${#str}
 
	for (( i=$length-1; i>=0; i-- )); do
        reversed="${reversed}${str:i:1}"
	done
 
	if [ "$str" == "$reversed" ]; then
        echo "The entered string is a palindrome."
	else
        echo "The entered string is not a palindrome."
	fi
}
 
echo -n "Enter a string: "
read input_string
 
is_palindrome "$input_string"

