#include <iostream>

struct MyStruct {
    int i;
    char ch;
    int i2;
};

int testCPP() {
    MyStruct s = {0x12345678, 'A', 'B'};
    std::cout << "&s.i = " << &s.i << std::endl;
    std::cout << "&s.ch = " << (void*)&s.ch << std::endl;
    std::cout << "&s.i2 = " << (void*)&s.i2 << std::endl;

    // 使用 __unaligned 修饰结构体，强制按照字节对齐方式存储
    // struct __unaligned MyUnalignedStruct {
    struct MyUnalignedStruct {
        int i;
        char ch;
        int i2;
    };

    MyUnalignedStruct u = {0x12345678, 'A'};
    std::cout << "&u.i = " << &u.i << std::endl;
    std::cout << "&u.ch = " << (void*)&u.ch << std::endl;
    std::cout << "&u.i2 = " << (void*)&u.i2 << std::endl;

    return 0;
}
/////////////////////////////////////

#include <stdio.h>

// struct MyStruct {
//     int i;
//     char ch;
// };

int testC() {
    struct MyStruct s = {0x12345678, 'A', 'B'};
    printf("((char*)&s.i)[0] = %0x\n", ((char*)&s.i)[0]);
    printf("((char*)&s.i)[1] = %0x\n", ((char*)&s.i)[1]);
    printf("((char*)&s.i)[2] = %0x\n", ((char*)&s.i)[2]);
    printf("((char*)&s.i)[3] = %0x\n", ((char*)&s.i)[3]);

    printf("&s.i = %p\n", (void*)&s.i);
    printf("&s.ch = %p\n", (void*)&s.ch);
    printf("&s.i2 = %p\n", (void*)&s.i2);

    // 使用 __unaligned 修饰结构体，强制按照字节对齐方式存储
    // struct __unaligned MyUnalignedStruct {
    struct MyUnalignedStruct {
        int i;
        char ch;
        int i2;
    };

    struct MyUnalignedStruct u = {0x12345678, 'A', 'B'};
    printf("&u.i = %p\n", (void*)&u.i);
    printf("&u.ch = %p\n", (void*)&u.ch);
    printf("&u.i2 = %p\n", (void*)&u.i2);
    printf("&u.i = %d\n", u.i);
    printf("&u.ch = %c\n", u.ch);
    printf("&u.i2 = %c\n", u.i2);
    printf("&u.i2 = %d\n", u.i2);

    return 0;
}


/*
2024/2/11 18:03:04

C语言，栈是从高到低还是从低到高地址？全局变量、局部变量、传入的实参和形参，分别是什么样的？

2024/2/11 18:03:09

在C语言中，栈是从高地址向低地址增长的。

全局变量存储在静态存储区（或数据段），它们在程序运行期间一直存在，并且可以在整个程序中被访问。全局变量分配在内存的固定位置。

局部变量是在函数内部定义的变量，它们在函数被调用时创建，在函数执行完毕后销毁。局部变量通常存储在栈上，每次函数调用时都会为局部变量分配一块内存空间。

传入的实参是在函数调用时传递给函数的值或变量。实参可以是任何类型的表达式，包括常量、变量、表达式等。

形参是函数定义时声明的参数，它们在函数被调用时接收传入的实参的值。形参类似于局部变量，在函数内部使用。它们通常存储在栈上，占用一定的内存空间。



2024/2/11 18:07:29

他们有很多个的时候，地址是增加还是减小？

2024/2/11 18:07:33

当有多个局部变量或多个形参时，它们在栈上按照从高地址向低地址的顺序分配内存空间。也就是说，每个新的局部变量或形参都会被分配在上一个局部变量或形参的下方，地址是递减的。

例如，当函数调用时，先为第一个局部变量或第一个形参分配内存，它们的地址较高。接着，为第二个局部变量或第二个形参分配内存，它们的地址较低，依次类推。这样，栈的地址是递减的。



&arg2 =     0x7ffdaa557c98
&arg1 =     0x7ffdaa557c9c
&i =        0x7ffdaa557cac
&j =        0x7ffdaa557cb0
&k =        0x7ffdaa557cb4
&global_i = 0x55ef738bc154
&global_j = 0x55ef738bc158
*/
int global_i = 0;
int global_j;
void test_big_endian(int arg1, int arg2){
    int i;
    int j;
    int k;
    printf("&arg1 =     %p\n", &arg1);
    printf("&arg2 =     %p\n", &arg2);
    printf("&i =        %p\n", &i);
    printf("&j =        %p\n", &j);
    printf("&k =        %p\n", &k);
    printf("&global_i = %p\n", &global_i);
    printf("&global_j = %p\n", &global_j);
}

int main(){
    test_big_endian(10, 11);
    testC();
    testCPP();
}