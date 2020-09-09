#!/bin/bash
#
# Author:dave lambert, dave@xyz.org
# Date:12 October 2005
# Description: Read filename from command line;
# process file size information with we
#
echo The number of lines in $1 is:
wc -l $1
echo The number of words in $1 is:
wc -w $1
echo  End of processing for $1

