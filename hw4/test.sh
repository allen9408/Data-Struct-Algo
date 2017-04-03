#!/bin/bash
# echo ==================================
# echo Generate Data \(size = 3, 5, 10\)
# echo ==================================
g++ ./datagen/data_gen.cpp -o datagen/datagen
./datagen/datagen 3 >> data3.txt
cp data3.txt ./q1
mv data3.txt ./q2
./datagen/datagen 5 >> data5.txt
cp data5.txt ./q1
mv data5.txt ./q2
./datagen/datagen 10 >> data10.txt
cp data10.txt ./q1
mv data10.txt ./q2
# Compile source code
g++ q1/q1.cpp -o q1/q1
g++ q2/q2.cpp -o q2/q2
g++ q3/q3.cpp -o q3/q3

echo ==================================
echo Q1 \& Q2 Size = 3
echo ==================================
echo 2-3 Tree
./q1/q1 ./q1/data3.txt
echo R-B Tree
./q2/q2 ./q2/data3.txt

echo ==================================
echo Q1 \& Q2 Size = 5
echo ==================================
echo 2-3 Tree
./q1/q1 ./q1/data5.txt
echo R-B Tree
./q2/q2 ./q2/data5.txt

echo ==================================
echo Q1 \& Q2 Size = 10
echo ==================================
echo 2-3 Tree
./q1/q1 ./q1/data10.txt
echo R-B Tree
./q2/q2 ./q2/data10.txt

echo ==================================
echo Q3 Size = 1000000
echo ==================================
./datagen/datagen 1000000 >> ./q3/data1000000.txt
./q3/q3 ./q3/data1000000.txt
rm ./q3/data1000000.txt
echo ==================================
echo Q3 Size = 2000000
echo ==================================
./datagen/datagen 2000000 >> ./q3/data2000000.txt
./q3/q3 ./q3/data2000000.txt
rm ./q3/data2000000.txt
echo ==================================
echo Q3 Size = 4000000
echo ==================================
./datagen/datagen 4000000 >> ./q3/data4000000.txt
./q3/q3 ./q3/data4000000.txt
rm ./q3/data4000000.txt
echo ==================================
echo Q3 Size = 8000000
echo ==================================
./datagen/datagen 8000000 >> ./q3/data8000000.txt
./q3/q3 ./q3/data8000000.txt
rm ./q3/data8000000.txt
echo ==================================
echo Q3 Size = 16000000
echo ==================================
./datagen/datagen 16000000 >> ./q3/data16000000.txt
./q3/q3 ./q3/data16000000.txt
rm ./q3/data16000000.txt
