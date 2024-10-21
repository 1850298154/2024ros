[C/C++ typedef用法](https://www.cnblogs.com/ggjucheng/archive/2011/12/27/2303238.html)

# **引言**

typedef 声明，简称 typedef，为现有类型创建一个新的名字。比如人们常常使用 typedef 来编写更美观和可读的代码。所谓美观，意指 typedef 能隐藏笨拙的语法构造以及平台相关的数据类型，从而增强可移植性和以及未来的可维护性。
在编程中使用typedef目的一般有两个，一个是给变量一个易记且意义明确的新名字，另一个是简化一些比较复杂的类型声明。

typedef的使用方法如下:

```cpp
typedef existing_type new_type_name ;
```

注意:typedef 并不创建新的类型。它仅仅为现有类型添加一个同义字。

# **typedef的最简单使用**

```cpp
typedef int size;
typedef unsigned int WORD;
```


第一个声明定义了一个char的同义词，名字为C，你可以在任何需要int的上下文使用size。
第二个声明定义了一个unsigned int的同义词,名字为WORD，你可以在任何需要int的上下文使用WORD。

# **typedef和数组,指针**

我们可以不用象下面这样重复定义有 81 个字符元素的数组：

```cpp
char line[81]; 
char text[81];
```

定义一个 typedef，每当要用到相同类型和大小的数组时，可以这样：

```cpp
typedef char Line[81]; 
Line text, secondline;
```

同样，可以象下面这样隐藏指针语法：

```cpp
typedef char * pstr; 
pstr str = "abc";
int mystrcmp(pstr, pstr);
```

# **typedef和函数**

函数指针一般用于回调，例如信号处理，libcurl等会应用到回调。回调是比较常用的技术，而回调就要涉及函数指针。
当我们的程序中有以下函数:

```cpp
void printHello(int i);
```

然后我们要定义一个函数指针，指向printHello，并且调用这个方法，代码如下:

```cpp
void (*pFunc)(int);
pFunc = &printHello;
(*pFunc)(110);
```

其中void (*pFunc)(int)是声明一个函数指针，指向返回值是void，调用参数是(int)的函数，变量名是pFunc,pFunc就是函数指针了，以前是函数指针的简单用法。
大家可以看到，声明一个函数指针是比较复杂的，尤其是当你要在多处地方声明同一个类型的函数指针变量，代码更加复杂，所以有下面简化的做法:

```cpp
typedef void (*PrintHelloHandle)(int);
```

使用代码如下:

```cpp
PrintHelloHandle pFunc;
pFunc = &printHello;
(*pFunc)(110);
```

以后其他地方的程序需要声明类似的函数指针，只需要下面代码:

```cpp
PrintHelloHandle pFuncOther;
```

这样，我们的代码就变得更加简洁易懂。

# **typedef心得**

大家在看typedef和数组,指针以及typedef和函数，可能会觉得typedef比较复杂，但是其实typedef 行为有点像 #define 宏，用其实际类型替代同义字。
请看看下面例子

```cpp
typedef char * pstr; 
pstr mystr;
```

代码pstr mystr，展开之后就是char * mystr,把mystr，替换为语句typedef char * pstr的pstr，展开之后还是char * mystr。
typedef并不创建新的类型，typedef 在编译时被解释，因此让编译器来应付超越预处理器能力的文本替换而已。
这些规则可以应用到typedef和数组:

```cpp
typedef char Line[81];
Line text;
```

把text替换为typedef char Line[81]的Line，展开之后就是

```cpp
char text[81]; 
```


也可以应用到最复杂的typedef和指针

```cpp
typedef void (*PrintHelloHandle)(int);
PrintHelloHandle pFunc;
```

将pFunc替换typedef void (*PrintHelloHandle)(int),展开之后就是

```cpp
void (*pFunc)(int);
```

其实就是声明一个pFunc函数指针而已，根本没有PrintHelloHandle这种类型。