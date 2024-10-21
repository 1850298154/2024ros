/*

g++ 06_new.cpp
C:\Users\ADMINI~1\AppData\Local\Temp\ccTe04AD.o:06_new.cpp:(.rdata$.refptr._ZTV7Derived[.refptr._ZTV7Derived]+0x0): undefined reference to `vtable for Derived'
C:\Users\ADMINI~1\AppData\Local\Temp\ccTe04AD.o:06_new.cpp:(.rdata$.refptr._ZTV4Base[.refptr._ZTV4Base]+0x0): undefined reference to `vtable for Base'   
collect2.exe: error: ld returned 1 exit status  

这个错误提示是  [[[编译器]]]  给出的，可能是由于链接时找不到类 Base 和 Derived 的虚函数表（即 vtable）引起的。可能的原因包括：
1. [[[编译器]]]  没有找到完整的类定义或者实现，需要确保在编译时已经将所有相关源文件都  [[[编译并链接]]]  在一起。
2. 可能在类声明中存在纯虚函数，但是没有提供纯虚函数的实现，需要为这些函数提供实现或者将其改为普通虚函数。
可能存在多次定义同一个类的虚函数表，需要检查是否有重复定义或者重复包含头文件的情况。
你可以仔细检查代码中是否存在以上问题，并进行相应的修改和调试。

#         .cpp文件报错和 .o文件报错分别都是什么给出的？
在你提供的错误信息中，".cpp" 文件报错是  [[[编译器 ]]] 在  {{编译}}  源文件  时给出的错误信息，而 ".o" 文件报错是  [[[链接器]]]  在将  目标文件  {{链接}}  为可执行文件时给出的错误信息。
1. ".cpp" 文件报错：
这个错误通常是  [[[编译器]]]  在编译源文件时发现的  (((语法错误、类型错误)))  或其他编译问题。  [[[编译器]]]  会对源文件逐行进行  (解析和编译)  ，并给出相应的错误提示。在你提供的错误信息中，".cpp" 文件报错的具体内容是 `undefined reference`，表示  [[[编译器]]]  在  {链接}  阶段  找不到对应的函数或变量的定义。
2. ".o" 文件报错：
当  [[[编译器]]]  成功编译源文件后，它会将源文件编译生成目标文件（通常以 `.o` 或 `.obj` 结尾），然后将这些目标文件交给  [[[链接器]]]  进行链接。  [[[链接器]]]  将多个  目标文件  合并为一个  可执行文件  ，并解决函数和变量的  (((引用)))  关系  。在链接过程中，如果  [[[链接器]]]  找不到某个函数或变量的定义，就会给出类似于 `undefined reference` 的错误信息。
综上所述，".cpp" 文件报错是  [[[编译器]]]  在编译源文件时给出的错误信息，而 ".o" 文件报错是  [[[链接器]]]  在链接目标文件时给出的错误信息。这两种报错通常都需要根据具体的错误提示进行调试和修复。


#         C++虚函数和纯虚函数


C++中的   [[[虚函数]]]  是为了实现  [[[多态性]]]  而设计的。一个虚函数可以在  {基类}  中被  (声明)  并在  {派生类}  中被  重新  (定义)  。当通过基类指针或引用调用虚函数时，将根据实际指向的对象类型来调用正确的函数实现。虚函数可以使用关键字`virtual`来声明。

纯虚函数是  [[[没有函数体]]]  的虚函数。一个类中如果存在纯虚函数，则这个类就成为了  [[[抽象类]]]  。抽象类是  不能被实例化的。派生类必须   实现(所有)的纯虚函数   才能被实例化。纯虚函数可以使用关键字`virtual`和`=0`来声明，例如：
```
virtual void func() = 0;
```

总之，虚函数和纯虚函数都是为了实现多态性而设计的。虚函数可以有函数体，而纯虚函数没有函数体。

*/
#include <iostream>
struct MyClass{};
//undefined reference to vtable for
// 这是因为 类 在头文件中声明了 父类 的虚函数，但是没有实现虚函数
// 解决办法：
// 1.在类的头文件中注释掉 虚函数 声明
// 2.在类的源文件中实现 虚函数 功能
struct Base{
// class Base{
// public:
    // virtual void move(); // undefined reference to `vtable for Derived'
    // virtual void move() {}
    void move() {}  
    /*
    06_new_delete_cast.cpp: In function 'int main()':
    06_new_delete_cast.cpp:66:58: error: cannot dynamic_cast 'basePtr' (of type 'struct Base*') to type 'struct Derived*' (source type is not polymorphic多态的)
        Derived *derivedPtr = dynamic_cast<Derived *>(basePtr); // 01;31m^
    */
};
struct Derived: public Base{
// class Derived: public Base{
// public:
    // virtual void move() override; // undefined reference to `vtable for Derived'
    // virtual void move() override {}
    void move()  {}
};
int main()
{
    // C++ 运算符有很多种，其中包括 `new`、`delete`、`dynamic_cast` 和 `static_cast`。下面将对这些运算符进行简要说明：
    // 1. `new`：用于在堆上动态分配内存并创建对象。它返回指向已分配内存的指针，并可以调用对象的构造函数来初始化该内存。
    int *ptr = new int;           // 分配一个 int 类型的内存，并将指针赋给 ptr
    int *arr = new int[10];       // 分配一个含有 10 个 int 类型元素的数组，并将指针赋给 arr
    MyClass *obj = new MyClass(); // 创建一个 MyClass 类的对象，并将指针赋给 obj
    // 2. `delete`：用于释放通过 `new` 分配的内存，并调用对象的析构函数进行清理。必须与 `new` 配对使用。
    delete ptr;   // 释放由 new 分配的内存
    delete[] arr; // 释放由 new [] 分配的内存
    delete obj;   // 调用 MyClass 对象的析构函数，并释放内存
    // 3. `dynamic_cast`：用于在  [[[运行时]]]  进行安全的向下转型。它可以将基类指针或引用转换为派生类指针或引用，并检查类型转换的有效性。
    Base *basePtr = new Derived();                          // 创建一个派生类对象，并将指针赋给基类指针
    // Derived *derivedPtr = dynamic_cast<Derived *>(basePtr); // 将基类指针转换为派生类指针  多态
    // Derived *derivedPtr = basePtr; // 将基类指针转换为派生类指针
    /*
    06_new_delete_cast.cpp: In function 'int main()':
    06_new_delete_cast.cpp:72:27: error: invalid conversion from 'Base*' to 'Derived*' [-fpermissive]
        Derived *derivedPtr = basePtr; // 01;31m^~~~~~~
    */
    Derived *derivedPtr = (Derived *)basePtr; // 没有报错  注意：多态、覆写、重写
    
    if (derivedPtr)
    {
        // 转换成功，可以使用 derivedPtr 操作 Derived 类的成员
    }
    else
    {
        // 转换失败，basePtr 指向的对象不是 Derived 类型
    }
    // 4. `static_cast`：用于进行静态类型转换，它在   [[[编译时]]]    进行类型检查，并可以执行一些基本的类型转换。
    int num = 10;
    double result = static_cast<double>(num);     // 将整型 num 转换为浮点型
    void *voidPtr = static_cast<void *>(basePtr); // 将基类指针转换为 void 指针
    // 需要注意的是，运算符的使用应根据具体情况和需求而定，同时遵循运算符的使用规则和最佳实践。
}
