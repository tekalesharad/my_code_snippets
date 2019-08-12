#!/bin/bash
#
# Author, dave lambert, dave@xyz.org
# Date, 12 October 2005
# Description: Add a user for database access
# Requires a user name and database table name on the
# command line
#
if [ $# -ne 2 ];
then
echo "number of args provided: " $#
echo You must provide a user name and a database table name .
exit
fi
# Begin processing :
# Store command line parameters in shell variables
DB_USER=$1
DB_TABLE=$2

echo "DB_USER :" ${DB_USER}
echo "DB_TABLE :" $DB_TABLE
