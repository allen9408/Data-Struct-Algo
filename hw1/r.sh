#!/bin/bash
if [[ $1 -eq '1' ]]; then
	#statements
	echo 8
	time ./q1_a ./hw1-1.data/8int.txt 8
	echo 32
	time ./q1_a ./hw1-1.data/32int.txt 32
	echo 128
	time ./q1_a ./hw1-1.data/128int.txt 128
	echo 512
	time ./q1_a ./hw1-1.data/512int.txt 512
	echo 1024
	time ./q1_a ./hw1-1.data/1024int.txt 1024
	echo 4096
	time ./q1_a ./hw1-1.data/4096int.txt 4096
	echo 4192
	time ./q1_a ./hw1-1.data/4192int.txt 4192
	echo 8192
	time ./q1_a ./hw1-1.data/8192int.txt 8192
fi
if [[ $1 -eq '2' ]]; then
	#statements
	echo 8
	time ./q1_b ./hw1-1.data/8int.txt 8
	echo 32
	time ./q1_b ./hw1-1.data/32int.txt 32
	echo 128
	time ./q1_b ./hw1-1.data/128int.txt 128
	echo 512
	time ./q1_b ./hw1-1.data/512int.txt 512
	echo 1024
	time ./q1_b ./hw1-1.data/1024int.txt 1024
	echo 4096
	time ./q1_b ./hw1-1.data/4096int.txt 4096
	echo 4192
	time ./q1_b ./hw1-1.data/4192int.txt 4192
	echo 8192
	time ./q1_b ./hw1-1.data/8192int.txt 8192
fi


