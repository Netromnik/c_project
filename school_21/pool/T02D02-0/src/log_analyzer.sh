#!/bin/bash
path_f=$1

if [[ -f $path_f ]]
then
  echo "The variable is greater than 10."
fi

count=$(cat $path_f | wc -l)
uniq_f=$(cut -d '-' -f1 $path_f | sort -u |wc -l)
uniq_hash_f=$(cut -d '-' -f6 $path_f | sort -u |wc -l)
echo $count $uniq_f $uniq_hash_f
