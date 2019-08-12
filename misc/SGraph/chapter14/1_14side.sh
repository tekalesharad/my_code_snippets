#!/bin/bash
#
# Author,                      dave lambert, dave@xyz .org
# Date,                         12 October 2005
# Description:             Collect info on core dump files
# and create file with directory sizes
#
find /home/pi/SGraph/dummy -name "example*" -exec rm {} \;
du  /home/pi/SGraph/dummy  >/tmp/home_sizes
