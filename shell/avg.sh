#!/usr/bin/bash

# Function to calculate the average of given numbers
calculate_average() {
    sum=0
    count=0

    for number in "${@}"; do
        sum=$((sum + number))
        ((count++))
    done

    average=$((sum / count))
    echo "Average: $average"
}

# Function to find the maximum from given numbers
find_max() {
    max=$1

    for number in "${@}"; do
        if [ $number -gt $max ]; then
            max=$number
        fi
    done

    echo "Maximum: $max"
}

# Function to find the minimum from given numbers
find_min() {
    min=$1

    for number in "${@}"; do
        if [ $number -lt $min ]; then
            min=$number
        fi
    done

    echo "Minimum: $min"
}

# Main program
echo "Enter numbers separated by spaces:"
read -a numbers_array

calculate_average "${numbers_array[@]}"
find_max "${numbers_array[@]}"
find_min "${numbers_array[@]}"

