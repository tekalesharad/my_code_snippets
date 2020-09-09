#! /bin/bash
#
# Author, dave lambert, dave@xyz.org
# Date, 12 October 2005
# Description : Read filename with READ;
# process file size information with wc
#
echo Enter a filename to process:
read THEFILE
echo The number of lines in $THEFILE is:
wc -l $THEFILE
echo The number of words in $THEFILE is:
wc -w $THEFILE
echo End of processing for $THEFILE

