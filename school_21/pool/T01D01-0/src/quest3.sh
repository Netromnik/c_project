#!/bin/bash
mv door_management_fi door_management_files
cd door_management_files 
mkdir door_configuration  door_logs door_map
for i in $(ls door_*.conf);do mv  $i door_configuration/$i;done
for i in $(ls door_*.log); do mv  $i door_logs/$i;done
mv door_map_1.1 door_map/door_map_1.1
cd .. 
shmod 777 *
sh ./ai_door_management_module.sh
