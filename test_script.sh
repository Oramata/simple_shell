#!/bin/bash

output=$(echo "ls" | ./hsh)
expected_output=$(ls)

if [ "$output" == "$expected_output" ]; then
	echo "Test passed"
else
	echo "Test failed"
fi
