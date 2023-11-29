#!/bin/bash

echo "Enter array size"
read n

echo "Enter the array elements"
i=0

while [ $i -lt $n ]
do
    read nums[$i]
    i=$(expr $i + 1)
done

echo "Array elements"
i=0

while [ $i -lt $n ]
do
    echo ${nums[$i]}
    i=$(expr $i + 1)
done

for ((i = 0; i < n; i++ ))
do
    for ((j = i; j < n; j++ ))
    do
        if [ ${nums[$i]} -gt ${nums[$j]} ]; then
            t=${nums[$i]}
            nums[$i]=${nums[$j]}
            nums[$j]=$t
        fi
    done
done

echo "Sorted elements"

for ((i = 0; i < n; i++ )) 
do
    echo ${nums[$i]}
done

