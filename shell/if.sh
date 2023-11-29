#!/usr/bin/bash

echo "enter the numbers"
read num1 num2
echo $num1 $num2

if [ $num1 -ge $num2 ]
then
echo "$num1 is greater than $num2"
else
echo "$num2 is greater than $num1"
fi


echo "enter the numbers"
read num3 num4
echo $num3 $num4

if [[ $num3 > $num4 ]]
then
echo "$num3 is greater than $num4"
else
echo "$num4 is greater than $num3"
fi
