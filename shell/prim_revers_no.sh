#!/bin/bash

# Function to check if a number is prime
is_prime() {
    num=$1
    for ((i = 2; i <= num/2; i++))
    do
        ans=$((num % i))
        if [ $ans -eq 0 ]
        then
            echo "$num is not a prime number."
            exit 0
        fi
    done
    
    return 0  # Prime
}

# Function to reverse a number
reverse_number() {
    num=$1
    reverse=0
    
    while [ $num -gt 0 ]; do
        digit=$((num % 10))
        reverse=$((reverse * 10 + digit))
        num=$((num / 10))
    done
    
    echo $reverse
}

# Read the number from the user
read -p "Enter a number: " number

# Check if the number is prime
if is_prime "$number"; then
    echo "$number is a prime number."
else
    echo "$number is not a prime number."
fi

# Print the reverse of the number
reversed=$(reverse_number "$number")
echo "Reverse of $number is $reversed"
