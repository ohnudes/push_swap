#!/bin/bash

program="./push_swap"

for ((i=1; i<= 10; i++)); do
	numbers_10=$(shuf -i -2147483648-2147483647 -n 10)
	numbers_20=$(shuf -i -2147483648-2147483647 -n 20)
	numbers_50=$(shuf -i -2147483648-2147483647 -n 50)

	echo "Run $i with 10 random numbers: $numbers_10"
	$program $numbers_10

	echo "Run $i with 20 random numbers: $numbers_20"
	$program $numbers_20

	echo "Run $i with 50 random numbers: $numbers_50"
	$program $numbers_50

	echo "========================"
done
