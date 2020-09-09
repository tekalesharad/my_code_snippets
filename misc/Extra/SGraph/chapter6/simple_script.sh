#!/bin/bash

i=0
while  [[ $i < 100 ]]
do
	echo "Print $i"
	i=$i+1 
done
echo "Process running"
sleep 100
echo "Started again"
sleep 100
echo "And started agaib"
