/*
这段代码展示了使用成员函数指针的三种不同用法：

1. `(obj.*funcPtr)()`：通过对象调用成员函数指针。这种用法是在已经有对象的情况下，直接使用对象和成员函数指针来调用相应的成员函数。这种方式在需要  动态地选择调用  [[[某个成员函数]]]  时非常有用。

   ```cpp
   MyClass obj;
   (obj.*funcPtr)(); // 通过对象调用成员函数指针
   ```

2. `(objPtr->*funcPtr)()`：通过指针调用成员函数指针。这种用法是在有对象指针的情况下，使用指针和成员函数指针来调用相应的成员函数。这种方式在需要通过指针  间接调用  成员函数  时非常有用。

   ```cpp
   MyClass* objPtr = &obj;
   (objPtr->*funcPtr)(); // 通过指针调用成员函数指针
   ```

3. `obj.myFunction()`：直接通过对象调用成员函数。这种方式是最常见的直接调用成员函数的方式，不需要使用成员函数指针。这里只是为了对比展示而写的代码。

   ```cpp
   obj.myFunction();
   ```

这三种用法的特殊之处在于，成员函数指针  允许在  运行时  动态地选择 要调用的成员函数，而不是在  编译时  固定  调用某个成员函数。这对于需要根据  不同的条件或情况  选择调用不同成员函数的场景非常有用。














*/


// 相比于 C 语言，C++ 引入了一些新的运算符。以下是一些 C++ 中具有特殊功能或用途的运算符：

#include<iostream>
// 1. `::` 作用域解析运算符：用于访问命名空间、类、结构体或枚举中的成员。


namespace MyNamespace {
    int value = 100000000;
}

int value = -9999999;
int test1() {
    int value = 20;
    std::cout << MyNamespace::value << std::endl; // 访问命名空间 MyNamespace 中的 value
    std::cout << ::value << std::endl; // 访问全局作用域中的 value , 局部作用域 定义了也不行（必须全局）
    return 0;
}


// 2. `.*` 和 `->*` 成员指针运算符：用于通过指针访问类的成员函数或成员变量。


class MyClass {
public:
    void myFunction() {
        std::cout << "Hello, World!" << std::endl;
    }
};

int test2() {
    void (MyClass::*funcPtr)() = &MyClass::myFunction; // 定义一个成员函数指针

    MyClass obj;
    (obj.*funcPtr)(); // 通过对象调用成员函数指针

    MyClass* objPtr = &obj;
    (objPtr->*funcPtr)(); // 通过指针调用成员函数指针

    obj.myFunction();
    return 0;
}


// 3. `typeid` 运算符：用于获取对象或类型的运行时类型信息。


#include <typeinfo>

class MyBaseClass {
public:
    virtual ~MyBaseClass() {}
};

class MyDerivedClass : public MyBaseClass {};

int test3() {
    MyBaseClass* basePtr = new MyDerivedClass();
    if (typeid(*basePtr) == typeid(MyDerivedClass)) {
        std::cout << "basePtr 指向的对象是 MyDerivedClass 类型" << std::endl;
    }

    return 0;
}


// 4. `new` 和 `delete` 运算符可以进行重载。可以通过重载这两个运算符来自定义内存管理行为。


void* operator new(size_t size) {
    void* ptr = malloc(size);
    // 自定义内存分配逻辑
    return ptr;
}

void operator delete(void* ptr) {
    // 自定义内存释放逻辑
    free(ptr);
}


// 这些是一些 C++ 中特有的运算符，它们扩展了 C 语言的功能，并提供了更多的灵活性和便利性。需要注意的是，在使用这些运算符时，请遵循运算符的使用规则和最佳实践。

int main() {
    test1();
    test2();
    test3();
}