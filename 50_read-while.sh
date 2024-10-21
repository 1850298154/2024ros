#!/bin/bash
rostopic list > topic_list.txt

cat topic_list.txt | while read topic_name;
do
    echo "$topic_name" >> echo_info_1s.txt
    rostopic info "$topic_name" >> echo_info_1s.txt
    timeout 1s rostopic echo "$topic_name" >> echo_info_1s.txt
done


# while IFS= read -r topic
# do
#     timeout 2s rostopic echo "$topic" >> xxx.txt
#     timeout 2s rostopic echo "$topic" >> xxx.txt
#     timeout 2s rostopic echo "$topic" >> xxx.txt
# done < topic_list.txt
