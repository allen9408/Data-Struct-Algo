# 13:332:573  Homework  #1

*Name: Weiqing Ni*

*NetID: wn61*

*Note:*

*1. All time units are seconds.*

*2. More details: https://github.com/allen9408/Data-Struct-Algo*

## Q1

**Please make sure <u>DISTINCT INTEGERS</u> *(slides 1-12)* given by input files. Otherwise, the results might be different.**

**a) **$O(N^3)$

| Input size | Running time |
| :--------: | :----------: |
|     8      |    0.006     |
|     32     |    0.006     |
|    128     |    0.008     |
|    512     |    0.106     |
|    1024    |    0.739     |
|    4096    |    39.00     |
|    4192    |    41.85     |
|    8192    |   295.308    |

![1](https://cl.ly/2a0A3A2V3w2S/q1_a.png)

As the input size increases, the runnimg time increases approximately as the function $time = cN^3$. More details can be found in **Q3**.

**b)**$O(N^2logN)$

| Input size | Running time |
| :--------: | :----------: |
|     8      |    0.008     |
|     32     |    0.005     |
|    128     |    0.005     |
|    512     |    0.021     |
|    1024    |    0.083     |
|    4096    |    1.625     |
|    4192    |    1.788     |
|    8192    |    6.875     |

![2](https://cl.ly/3u2Q1p011k3o/q1_b.png)

As the input size increases, the runnimg time increases approximately as the function $time = cN^2logN$. More details can be found in **Q3**.

## Q2

| Input Size | Quick Find | Quick Union | Weighted Quick Union | Weighted Quick Union with PC |
| ---------- | ---------- | ----------- | -------------------- | ---------------------------- |
| 8          | 0.006      | 0.007       | 0.007                | 0.008                        |
| 32         | 0.005      | 0.006       | 0.004                | 0.004                        |
| 128        | 0.007      | 0.005       | 0.003                | 0.004                        |
| 512        | 0.019      | 0.006       | 0.004                | 0.005                        |
| 1024       | 0.036      | 0.006       | 0.006                | 0.006                        |
| 4096       | 0.160      | 0.022       | 0.024                | 0.027                        |
| 8192       | 0.362      | 0.078       | 0.060                | 0.068                        |

![3](https://cl.ly/2a0V3Z0u2S1b/quick_find.png)

![4](https://cl.ly/0S2Y3A3g2v2X/quick_union.png)

Programs using quick union runs faster than program using quick find in union operation.

## Q3

**3-Sum:**

q1_a: $O(N^3)$
$$
F(N) = file\ reading\ +\ find\ number\\
= N + N(N-1)(N-2)\\
= N^3-3N^2 + 3N\\
g(N) = N^3\\
choose\ c=1, F(N) < cg(N)\ when\ N>1.
$$
q1_b:$(O(N^2lgN))$
$$
F(N) = N + N^2lgN\\
g(N) = N^2lgN\\
choose\ c = 2,  F(N) < cg(N)\ when\ N>2.
$$

**Dynamic Connectivity:**

quick find:
$$
F(N) = file\ reading\  +\ find\ max + init\ + union\\
= N+lgN+N+N\\
=lgN + 3N\\
g(N)=N\\
choose\ c = 4, F(N) < cg(N)\ when\ N>1.
$$
quick union:
$$
F(N) = file\ reading\  +\ find\ max + init\ + union(including\ find)\\
= N+lgN+N+2N\\
=lgN + 4N\\
g(N)=N\\
choose\ c = 5, F(N) < cg(N)\ when\ N>1.
$$
weighted quick union:
$$
F(N) = file\ reading\  +\ find\ max + init\ + union(including\ find)\\
= N+lgN+N+2lgN\\
=3lgN + 2N\\
g(N)=N\\
choose\ c = 5, F(N) < cg(N)\ when\ N>1.
$$
weighted quick union:
$$
F(N) = file\ reading\  +\ find\ max + init\ + union(including\ find)\\
= N+lgN+N+2lgN\\
=3lgN + 2N\\
g(N)=N\\
choose\ c = 5, F(N) < cg(N)\ when\ N>1.
$$

## Q4

**Is** $2^{n+1}=O(2^n)$**?**

Yes. 

$F(N) = 2^{n+1},\ g(N) = 2^n$, 

choose c = 3, $F(N)<3g(N)$ when $n>0$.



**Is **$2^{2n}=O(2^n)$**?**

Yes.

$F(N) = 2^{2n}, g(N) = 2^n,$

choose c=5, $F(N)<5g(N)$ when $n>0$.



## Q5

Sort: (From high to low)
$$
2^{2^{n+1}} > 2^{2^{n}} > (n+1)! > n! > e^n > lg(n!) > n*2^n > 2^n > (\frac32)^n\\
>n^3 > n^2 > nlgn > n > n^{lg(lgn)} > (lgn)^{lgn} > 2^{lgn} > (\sqrt2)^{lgn} > 2^{\sqrt{2lgn}}\\
>lg^2n > lg(n!) > ln(n) > n^{\frac{1}{lgn}} > lg*n > ln(ln(n)) > \sqrt{lgn} > lg*lg(n)\\
>lg(lg*n) > 1
$$

## Q6

**a)** 100$\times$100 Grid:

| steps | Running time | Threshold *p* |
| :---: | :----------: | :-----------: |
| 9539  |    0.009     |    0.9539     |
| 9422  |    0.010     |    0.9422     |
| 9221  |    0.007     |    0.9221     |
| 9378  |    0.008     |    0.9378     |
| 9476  |    0.007     |    0.9476     |
| 9394  |    0.007     |    0.9394     |

The average value of *p* is <u>0.9405</u>.

The standard deviation of *p* is <u>0.00983124</u>.

**b)**

|   N   | Grid Size |  Steps   | Running time |
| :---: | :-------: | :------: | :----------: |
|   8   |    64     |    35    |    0.009     |
|  32   |   1024    |   832    |    0.005     |
|  128  |   16384   |  14625   |    0.005     |
|  512  |  262144   |  257687  |    0.095     |
| 1024  |  1048576  | 1016684  |    0.610     |
| 4096  | 16777216  | 16483332 |    13.916    |
| 8192  | 67108864  | 66795250 |    80.431    |
| 16384 | 268435456 |          |              |

$$
F(N) = N^2 + 2NlgN + 4N^2lg N \\
= O(N^2lgN)
$$



