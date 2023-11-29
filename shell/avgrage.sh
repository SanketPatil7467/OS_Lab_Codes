#!/bin/bash

average()
{
    rem=0
    sum=0
    cnt=0
    i=1
    while [ $n -gt 0 ]
    do
    	rem=`expr $n % 10`
    	sum=`expr $sum + $rem`
    	n=`expr $n / 10`
    	((cnt++))
    done
    cnt=`expr $sum / $cnt`
    echo "Average = $cnt"
}

minimum()
{
    rem=0
    min1=`expr $n % 10`
    while [ $n -gt 0 ]
    do
    	rem=`expr $n % 10`
    	if [[ $rem -lt $min1 ]]
        then
            min1=$rem
        fi
    	n=`expr $n / 10`
    done
    
    echo "Minimun = $min1"
}

maximum()
{
    rem=0
    max1=`expr $n % 10`
    while [ $n -gt 0 ]
    do
    	rem=`expr $n % 10`
    	if [[ $rem -gt $max1 ]]
        then
            max1=$rem
        fi
    	n=`expr $n / 10`
    done

    echo "Maximum = $max1"
}

echo "Enter the number-"
read n


echo -e "Enter Operation\n1. Average\n2. Max\n3. Min"
read ch

case $ch in
    1) average $n ;;
    2) maximum $n ;;
    3) minimum $n ;;
    *) echo "Wrong choice" ;;
esac

