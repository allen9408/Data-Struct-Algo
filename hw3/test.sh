#!/bin/bash
echo =======================
echo 1024
echo hw2
time ../hw2/q5_a ../hw2/dataset/data1.1024 1024 ../hw2/dataset/data2.1024
echo hw3
time ./q2_b ../hw2/dataset/data1.1024 1024 ../hw2/dataset/data2.1024
echo =======================
echo 2048
echo hw2
time ../hw2/q5_a ../hw2/dataset/data1.2048 2048 ../hw2/dataset/data2.2048
echo hw3
time ./q2_b ../hw2/dataset/data1.2048 2048 ../hw2/dataset/data2.2048
echo =======================
echo 4096
echo hw2
time ../hw2/q5_a ../hw2/dataset/data1.4096 4096 ../hw2/dataset/data2.4096
echo hw3
time ./q2_b ../hw2/dataset/data1.4096 4096 ../hw2/dataset/data2.4096
echo =======================
echo 8192
echo hw2
time ../hw2/q5_a ../hw2/dataset/data1.8192 8192 ../hw2/dataset/data2.8192
echo hw3
time ./q2_b ../hw2/dataset/data1.8192 8192 ../hw2/dataset/data2.8192
echo =======================
echo 16384
echo hw2
time ../hw2/q5_a ../hw2/dataset/data1.16384 16384 ../hw2/dataset/data2.16384
echo hw3
time ./q2_b ../hw2/dataset/data1.16384 16384 ../hw2/dataset/data2.16384
echo =======================
echo 32768
echo hw2
time ../hw2/q5_a ../hw2/dataset/data1.32768 32768 ../hw2/dataset/data2.32768
echo hw3
time ./q2_b ../hw2/dataset/data1.32768 32768 ../hw2/dataset/data2.32768
echo =======================
echo 1000000
echo hw2
time ../hw2/q5_a ../hw2/dataset/data1.1000000 1000000 ../hw2/dataset/data2.1000000
echo hw3
time ./q2_b ../hw2/dataset/data1.1000000 1000000 ../hw2/dataset/data2.1000000