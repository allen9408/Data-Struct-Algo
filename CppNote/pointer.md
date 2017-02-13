#Pointer

**指针变量定义**

```c++
int *p;
char *cptr;
```

**使用`p=&x`将变量x的地址存入指针变量p：**

```c++
int x, *p = &x;
```

**指向指针的常量：**

```c++
const	 int	 *p = &x;
```

指针指向的内容为常量，不能修改指向内容

**常指针**：

``` c++
int	const*	p = &x;
```

指针本身是常量，固定指向某一变量

**指向常量的常指针**：

```C++
const int const* p = &x;
```

地址和地址中的值都不能改变



**动态变量创建：**

```c++
int *p = new int(10);	
int *arr = new int[10];
int (*data)[2] = new int[len][2];
```

**动态变量回收：**

```C++
delete p;
delete [] arr;
```



**字符串：**

```C++
char *s1, *s2;
char ch[] = "ffff";
s1 = ch;
s2 = new char[10];
strcpy(s2, "ghj");
```



**指针作为形式参数：**

```C++
void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}
// swap(&x, &y)
```

*输入参数一般使用值传递，输出参数必须使用指针传递*

**数组名作为形式参数**

```c++
void f(int arr[]) {
  cout << sizeof(arr) << endl;
}
int main(){
  int array[] = {1,2,3,4};
  f(array);
  return 0;
}
```

**返回指针的函数**

```c++
char *subString(char *s, int start, int end) {
  int len = strlen(s);
  if(/*look for error*/) {
    return NULL;
  }
  char *sub = new char[end - start + 2];
  strncpy(sub, s + start, end - start + 1);
  sub[end-start+1] = '\0';
  
  return sub;
}
```



**引用与引用传递**

```c++
void swap(int &a, int &b) {
  int c;
  
  c=a;
  a=b;
  b=c;
}
// swap(x,y)
```

