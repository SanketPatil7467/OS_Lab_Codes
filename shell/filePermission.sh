#!/bin/bash

check_file() {
    if [ -e "$1" ]; then
        echo "File '$1' exists."

        if [ -f "$1" ]; then
            echo "File '$1' is a regular file."
        elif [ -d "$1" ]; then
            echo "File '$1' is a directory."
        elif [ -b "$1" ]; then
            echo "File '$1' is a block special file (device file)."
        elif [ -c "$1" ]; then
            echo "File '$1' is a character special file (device file)."
        elif [ -L "$1" ]; then
            echo "File '$1' is a symbolic link."
        else
            echo "File '$1' is of unknown type."
        fi

        permissions=$(ls -l "$1")
        echo "Permissions for '$1': $permissions"
    else
        echo "File '$1' does not exist."
    fi
}

echo -n "Enter a file path: "
read filepath

check_file "$filepath"
