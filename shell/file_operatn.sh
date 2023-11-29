#!/bin/bash

while true; do
    echo "Choose an operation:"
    echo "1) Create new file"
    echo "2) Write into file"
    echo "3) Read contents line by line"
    echo "4) Read contents character by character"
    echo "5) Append to file"
    echo "6) Delete file"
    echo "7) Exit"
    read choice

    case $choice in
        1)  # Create new file
            echo "Enter the file name to create:"
            read filename
            touch "$filename"
            echo "File '$filename' created."
            ;;
        2)  # Write into file
            echo "Enter the file name to write to:"
            read filename
            if [ -f "$filename" ]; then
                echo "Enter the content to write (Ctrl+D to finish):"
                cat >> "$filename"
                echo "Content written to '$filename'."
            else
                echo "File '$filename' does not exist."
            fi
            ;;
        3)  # Read contents line by line
            echo "Enter the file name to read from:"
            read filename
            if [ -f "$filename" ]; then
            echo "Contents of '$filename' (line by line):"
                i=0 
                while read line
                do
                    i=$((i+1)) 
                    echo "Line $i = $line"
                done < "$filename"
            else
                echo "File '$filename' does not exist."
            fi
            ;;
        4)  # Read contents character by character
            echo "Enter the file name to read from:"
            read filename
            if [ -f "$filename" ]; then
                j=0  # Initialize j to 0
                echo "Contents of '$filename' (character by character):"
                while read -n 1 char
                do
                    j=$((j+1))  # Increment j for each character
                    echo "Char $j = $char"
                done < "$filename"
                echo
            else
                echo "File '$filename' does not exist."
            fi
            ;;
        5)  # Append to file
            echo "Enter the file name to append to:"
            read filename
            if [ -f "$filename" ]; then
                echo "Enter the content to append: "
                cat >> "$filename"
                echo "Content appended to '$filename'."
            else
                echo "File '$filename' does not exist."
            fi
            ;;
        6)  # Delete file
            echo "Enter the file name to delete:"
            read filename
            if [ -f "$filename" ]; then
                rm "$filename"
                echo "File '$filename' deleted."
            else
                echo "File '$filename' does not exist."
            fi
            ;;
        7)  # Exit
            echo "Exiting the script."
            exit 0
            ;;
        *)  # Invalid choice
            echo "Invalid choice. Please choose a valid option (1-7)."
            ;;
    esac
done
