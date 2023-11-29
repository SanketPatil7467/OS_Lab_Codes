#!/usr/bin/bash

echo "enter the numbers"
read num1 num2 num3
echo $num1 $num2 $num3

if [[ $num1 > $num2 ]]
then
if [[ $num1 > $num3 ]]
then
echo "$num1 is the greatest"
else
echo "$num3 is the greatest"
fi
else
if [[ $num2 > $num3 ]]
then 
echo "$num2 is the greatest"
else 
echo "$num3 is the greatest"
fi
