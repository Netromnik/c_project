./ai_door_management_module.sh
 ps |grep -v grep| grep "./ai_door_control.sh" | awk '{ print $1 }' | xargs kill -9
