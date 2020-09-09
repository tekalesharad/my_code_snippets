#!/bin/bash

pet=( DOG CAT MOUSE )
echo ${pet[0]}
echo ${pet[2]}
echo ${pet[1]}
echo "All array elements:" ${pet[*]}
echo "Nm of array elements:" ${#pet[*]}
