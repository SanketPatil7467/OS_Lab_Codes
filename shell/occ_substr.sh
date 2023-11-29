#!/bin/bash

input_string="$1"
substring="$2"

# Use 'grep' to count the occurrences of the substring in the string
occurrences=$(echo "$input_string" | grep -o "$substring" | wc -l)

# Display the result
echo "Occurrences of '$substring' in '$input_string': $occurrences"