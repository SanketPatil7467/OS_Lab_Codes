#!/bin/bash  

# echo "enter 1st int number:"
# read num1
# echo "enter 2nd int number:"
# read num2

num1=$1
num2=$2


add=`expr $num1 + $num2`
diff=`expr $num1 - $num2`
product=`expr $num1 \* $num2`
div=`expr $num1 / $num2`

echo "Addition : $add"
echo "Difference : $diff"
echo "Product : $product"
echo "Division : $div"


write_file(){
    echo "Sum of $num1 and $num2 is : $add" > addition.txt
    echo "Difference between $num1 and $num2 is : $diff" > difference.txt
    echo "Poduct of $num1 and $num2 is : $product" > multiplication.txt
    echo "Division of $num1 by $num2 is : $div" > division.txt
}
write_file

echo "############ Result are stored into respective file ############"
cat addition.txt
cat difference.txt
cat multiplication.txt
cat division.txt