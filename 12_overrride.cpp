//  Alt + F8    查看问题
//  Ctrl + .    快速修复
//  Ctrl + space    提示


/*

                            redefinition


12_overrride.cpp:37:8: error: redefinition of 'class Base'
  class Base {
        ^~~~
12_overrride.cpp:16:8: note: previous definition of 'class Base'
  class Base {
        ^~~~
12_overrride.cpp:44:8: error: redefinition of 'class Derived'
  class Derived : public Base {
        ^~~~~~~
12_overrride.cpp:23:8: note: previous definition of 'class Derived'
  class Derived : public Base {
        ^~~~~~~
12_overrride.cpp:80:7: error: redefinition of 'void func()'
  void func() {   // ?1;31mm^~~~
12_overrride.cpp:76:7: note: 'void func()' previously defined here
  void func() {
       ^~~~

*/


#include<iostream>
using namespace std;

// 在C++中，覆写（override）、重写（overwrite）、重载（overload）、重定义（redefine）是几个常用的概念。以下是它们对应的单词和具体的代码例子：

// 1. 覆写（override）：
//    - 单词：override
//    - 作用：在派生类中重新实现基类的虚函数
//    - 代码例子：

//	 cpp
	class Base {
	public:
		virtual void foo() {
			cout << "Base::foo()" << endl;
		}
	};

	class Derived : public Base {
	public:
		void foo() override {   // 使用override关键字进行覆写
			cout << "Derived::foo()" << endl;
		}
	};
	

// 2. 重写（overwrite）：
//    - 单词：overwrite
//    - 作用：在派生类中重新实现基类的非虚函数
//    - 代码例子：

//	 cpp
	class Base2 {
	public:
		void bar() {
			cout << "Base::bar()" << endl;
		}
	};

	class Derived2 : public Base2 {
	public:
		void bar() {   // 在派生类中重写基类的非虚函数
			cout << "Derived::bar()" << endl;
		}
	};
	

// 3. 重载（overload）：
//    - 单词：overload
//    - 作用：在同一个作用域内，根据函数参数的不同提供多个具有相同名称但参数类型或个数不同的函数
//    - 代码例子：

//	 cpp
	class MyClass {
	public:
		void func(int num) {
			cout << "func(int): " << num << endl;
		}

		void func(double num) {
			cout << "func(double): " << num << endl;
		}
	};
	

// 4. 重定义（redefine）：
//    - 单词：redefine
//    - 作用：在同一个作用域内，重新定义已有的函数或变量
//    - 代码例子：

//	 cpp
	void func() {
		cout << "Original func()" << endl;
	}

	void func2() {   // 重定义已有的函数
		cout << "Redefined func()" << endl;
	}
	

// 以上是C++中覆写、重写、重载、重定义对应的单词和代码例子。请注意，在实际编程中，要根据具体情况选择使用适当的概念和技术。
int main() {}
/*
int main() {}
如果没有  main 函数
D:/Dsoftware/MinGW/zip/x86_64-8.1.0-release-win32-seh-rt_v6-rev0/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/../../../../x86_64-w64-mingw32/lib/../lib/libmingw32.a(lib64_libmingw32_a-crt0_c.o):crt0_c.c:(.text.startup+0x2e): undefined reference to `WinMain'
collect2.exe: error: ld returned 1 exit status
*/