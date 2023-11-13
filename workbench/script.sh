#!/bin/bash

program="./push_swap"

for ((i=1; i<=10; i++)); do
    numbers_10=()
    
    for ((j=1; j<=10; j++)); do
        random_number=$((RANDOM * 2 - 32768))
        numbers_10+=($random_number)
    done

	rm input.txt
    echo "Run $i with 10 random numbers: ${numbers_10[@]}"
    
    # Use a conditional check for the last element
    last_index=$(( ${#numbers_10[@]} - 1 ))
    for ((j=0; j<${#numbers_10[@]}; j++)); do
        printf "%s" "${numbers_10[j]}"
        [ "$j" -eq "$last_index" ] || printf " "
    done >> input.txt  # Append to the file to preserve newline after each run

	if output="$(./push_swap $(cat input.txt))"; then
        echo "Program executed successfully"
        echo "Output: $output"
    else
        echo "Error: Program execution failed"
        echo "Error Output: $output"
        exit 1  # Exit the script if there's an error
    fi

    echo "========================"
done
