/*
MyClass obj(); // 错误写法
MyClass obj{}; // 正确写法，调用默认构造函数
MyClass obj;  // 等价于上一行，也是正确写法


///////////
#include <iostream>
using namespace std;

struct MyStruct {
  int x;
  double y;
  MyStruct(int a, double b): x(a), y(b) {}
};

int main() {
  MyStruct s1(5, 3.14); // 使用构造函数初始化
  MyStruct s2 = {3, 2.718}; // 使用花括号列表初始化
  cout << s1.x << " " << s1.y << endl; // 输出：5 3.14
  cout << s2.x << " " << s2.y << endl; // 输出：3 2.718
  return 0;
}


*/
struct MyClass
{
    /* data */
};

void func(MyClass obj) {

}
void func2(void* p) {

}

int main() {
//   func(MyClass); //03_class_brace.cpp:11:15: error: expected primary-expression before ')' token       
//   func2(&MyClass); //03_class_brace.cpp:11:15: error: expected primary-expression before ')' token
//   func2(MyClass); //03_class_brace.cpp:11:15: error: expected primary-expression before ')' token

  return 0;
}
