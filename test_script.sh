#!/bin/bash

# Test for ls command
ls_test()
{
	output=$(echo "ls" | ./hsh | sort)
	expected_output=$(ls | sort)
	if [ "$output" == "$expected_output" ]; then
		echo "ls command test passed"
	else
		echo "ls command test failed"
	fi
}


# Test for cd command
cd_test()
{
	# Change to home directory and then to previous directory to ensure we can return to it
	output=$(echo "cd ..; pwd" | ./hsh)
	expected_output=$(cd ..; pwd)
	if [ "$output" == "$expected_output" ]; then
		echo "cd command test passed"
	else
		echo "cd command test failed"
	fi
}

# Test for environment variables
setenv_test()
{
	# Test setting a new environment variable and then getting it
	output=$(echo "export TEST_VAR='test_value'; echo \$TEST_VAR" | ./hsh)
	expected_output="test_value"
	if [ "$output" == "$expected_output" ]; then
		echo "setenv command test passed"
	else
		echo "setenv command test failed"
	fi
}

# Run tests
ls_test
cd_test
setenv_test

