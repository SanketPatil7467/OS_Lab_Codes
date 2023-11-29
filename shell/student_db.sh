#!/bin/bash

# Functions for database operations

# Insert a new student
insert_student() {
  echo "Enter student name:"
  read name
  echo "Enter student ID:"
  read id
  echo "Enter student grade:"
  read grade
  echo "Name: $name, ID: $id, Grade: $grade" >> student_database.txt
  echo "Student record added."
}

# Delete a student by ID
delete_student() {
  echo "Enter student ID to delete:"
  read id
  grep -v "$id" student_database.txt > temp.txt #except data of $id all the other data is put in temp.txt
  mv temp.txt student_database.txt
  echo "Student record deleted."
}

# Update a student's grade by ID
update_student() {
  echo "Enter student ID to update:"
  read id
  echo "Enter new grade:"
  read new_grade
  sed -i "/$id/c\\$id, $new_grade" student_database.txt
  echo "Student record updated."
}

# Search for a student by ID
search_student() {
  echo "Enter student ID to search:"
  read id
  grep -q "$id" student_database.txt
  if [ $? -eq 0 ]; then
    grep "$id" student_database.txt
  else
    echo "Student not found."
  fi
}

# Main menu
while true; do
  echo "Student Database Menu"
  echo "1. Insert student"
  echo "2. Delete student"
  echo "3. Update student"
  echo "4. Search student"
  echo "5. Exit"
  read choice

  case $choice in
    1) insert_student;;
    2) delete_student;;
    3) update_student;;
    4) search_student;;
    5) echo "Exiting..."; exit;;
    *) echo "Invalid choice";;
  esac
done
