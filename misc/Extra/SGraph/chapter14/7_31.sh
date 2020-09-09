#!/bin/bash
echo -n “Enter the first number: ”; read x
echo -n “Enter the second number: ”; read y
add=$(($x + $y)) 
echo “Sum: $add”
sub=$(($x - $y)) 
echo “Difference: $sub”
mul=$(($x * $y)) 
echo “Product: $mul”
div=$(($x / $y)) 
echo “Quotient: $div”
mod=$(($x % $y))
# print out the answers:
echo “Remainder: $mod”



