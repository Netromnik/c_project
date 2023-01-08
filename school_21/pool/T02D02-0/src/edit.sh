#!/bin/bash
if [[ $# != 3 ]];then
	echo "ERR"
	exit 1
fi
path_f=$1
input_str=$2
replace=$3
cat $path_f 
if [[ $? != 0 ]]; then
	echo "ERR"
	exit 1
fi
date=$(sed "s/$input_str/$replace/g" $path_f)
if [[ $? != 0 ]]; then
	echo "ERR"
	exit 1
fi
echo $date > $path_f
if [[ $? != 0 ]]; then
	echo "ERR"
	exit 1
fi
echo Quest 1:$path_f - $(du  $path_f | awk '{print $1}') - $(date +"%G-%m-%d %H:%M") - $(shasum -a 256 $path_f | awk '{ print $1 }') - sha256 >> files.log
