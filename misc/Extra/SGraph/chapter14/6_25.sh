#!/bin/bash
# Author: dave lambert, dave@xyz.org
# Date: 12 October 2005
# Description: Read multiple filenames from command line;
# process each with we
#


if [ $# -lt 4 ]; then
 echo " Please enter 4 files names"
 echo "Format: "
 echo "./6_25.sh file1 file2 file3 file4"
 exit 1
fi

echo The script you are running is $0
echo The number of filenames you provided: $#  
echo The number of lines in file $1 is:
wc -l $1
echo The number of lines in file $2 is:
wc -l $2
echo The number of lines in file $3 is:
wc -l $3
echo The number of lines in file $4 is:
wc -l $4
