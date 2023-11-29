#!/usr/bin/bash

echo -e "enter 1st int number:"
read num1
echo -e "enter 2nd int number:"
read num2

div=`expr $num1 / $num2`
product=`expr $num1 \* $num2`
add=`expr $num1 + $num2`
diff=`expr $num1 - $num2`


echo "sum=$add"
echo "difference=$diff"
echo "product=$product"
echo "division=$div"

echo -e "enter 1st int/float number:"
read num3
echo -e "enter 2nd int/float number:"
read num4

div=`echo $num3 / $num4|bc`
product=`echo $num3 \* $num4|bc`
add=`echo $num3 + $num4|bc`
diff=`echo $num3 - $num4|bc`


echo "sum=$add"
echo "difference=$diff"
echo "product=$product"
echo "division=$div"

