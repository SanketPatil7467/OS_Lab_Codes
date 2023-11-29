#!/bin/bash

rem=0
sum=0
n=$1
while [ $n -gt 0 ]
do
    rem=`expr $n % 10`
    sum=`expr $sum + $rem`
    n=`expr $n / 10`
done
 
echo "Sum of digits of $1 = $sum"
