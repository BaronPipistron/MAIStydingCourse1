#!/bin/bash

while getopts ":p:s:" ARG;
do
        case "$ARG" in
p) prefix="$OPTARG" ;;
s) size="$OPTARG" ;;
        esac
done

suitable_files_list=$(sudo find / -path "/run" -prune -o -type f -name "${prefix}*" -printf "%s %p\n"|sort -n -r)
files_size=$(echo "$suitable_files_list"|awk '{sum+=$1} END {print sum}')
number_of_files=$(echo "$suitable_files_list"|wc -l)

if [[ "$number_of_files" -eq 0 ]]; then
        echo "Files with prefix $prefix were not found";
        exit 1;
fi

count_deleted_files=0

while [[ "$files_size" -gt "$size" ]];
do
        biggest_file=$(echo "$suitable_files_list"|head -n 1|awk '{print $2}')

        if [[ -r "$biggest_file" ]]; then
                echo "Deleted file: $biggest_file"
                rm "$biggest_file"

                count_deleted_files=$((count_deleted_files+1))
                suitable_files_list=$(echo "$suitable_files_list"|tail -n +2)
        else
                suitable_files_list=$(echo "$suitable_files_list"|tail -n +2)
        fi

        files_size=$(echo "$suitable_files_list"|awk '{sum+=$1} END {print sum}')
done

echo "Number of delted files: $count_deleted_files"