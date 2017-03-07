#DATA STRUCTURE & ALGORITHM
<center>*Rutgers Graduate*</center>

## Homework 1

**Working Environment:** 

1. OSX/ Linux
2. G++

**Compile:**

> cd HW1
>
> ./m.sh	

**Run**:

> ./q1_a {Input file} {input size}  
> ./q1_b {Input file} {input size}  
> ./q2_quickFind {input file} {input size}  
> ./q2_quickUnion {input file} {input size}  
> ./q2_quickUnion_weighted {input file} {input size}  
> ./q2_quickUnion_PC {input file} {input size}  
> ./q6_percolation {input size}  
>
> Example: ./q2_quickFind ./HW1-2.data/ 32pair.txt 32

**Test:**

> ./r.sh {config}
>
> config: 
>
> 1. Q1 3-SUM $O(N^3)$
> 2. Q1 3-SUM $O(N^2logN)$
> 3. Q2 quick find
> 4. Q2 quick union
> 5. Q2 weighted quick union 
> 6. Q2 weighted quick union with path compression
> 7. Q6 percolation

## Homework 2

### 1 

```bash
g++ q1.cpp -o q1
./q1 [test string]
```

### 2 

**a. Recursion**

```bash
g++ q2_a.cpp -o q2_a
./q2_a [cityList] [cityPairs] [requestlists]
```

**b. Stack**

```bash
g++ q2_b.cpp -o q2_a
./q2_b [cityList] [cityPairs] [requestlists]
```

### 3

Compile and Run:

```bash
g++ q3_a.cpp -o q3_a
g++ q3_b.cpp -o q3_b
./q3_a(b) [data_file] [data_size] [output_file]
Example : ./q3_a dataset/data1.32768 32768 dataset/data2.32768
```

Validate the result:

```bash
diff [output file] dataset/data1.[size]
```

### 5

**a. Recursive**

```bash
g++ q5_a.cpp -o q5_a 
./q5_a [input file] [input size] [output file] 
```

**b. Iterative**

```bash
g++ q5_b.cpp -o q5_b 
./q5_b [input file] [input size] [output file] 
```

