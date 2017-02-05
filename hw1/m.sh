#!/bin/bash
GCC=g++


$GCC q1_a.cpp -o q1_a
$GCC q1_b.cpp quickSort.cpp -o q1_b

$GCC q2_quickFind.cpp findMax.cpp -o q2_quickFind
$GCC q2_quickUnion.cpp findMax.cpp -o q2_quickUnion
$GCC q2_quickUnion_weighted.cpp findMax.cpp -o q2_quickUnion_weighted
$GCC q2_quickUnion_PC.cpp findMax.cpp -o q2_quickUnion_PC

$GCC q6_percolation.cpp -o q6_percolation