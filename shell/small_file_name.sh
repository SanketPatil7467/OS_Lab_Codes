#!/bin/bash

minLengthFileName=""
minLength=0

# Loop through each file in the current directory
for file in *; do
 # Get the length of the current file name
 currentLength=${#file}
 
 if [ -z "$minLengthFileName" ] || [ $currentLength -lt $minLength ]; then
    minLengthFileName="$file"
    minLength=$currentLength
 fi
done

# If a minimum length file name is found, print it. Otherwise, print an error message.
if [ -n "$minLengthFileName" ]; then
 echo "The smallest file name is '$minLengthFileName' with a length of $minLength characters."
else
 echo "Error: No files found in the current directory."
 exit 1
fi