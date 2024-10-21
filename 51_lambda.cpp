/*

-body
- **capture**：捕获列表，定义了lambda表达式可以访问的外部变量。可以为空，或者捕获一个或多个变量。捕获方式有值捕获（`=`或明确指定变量名）、引用捕获（`&`）、隐式捕获（`=`或`&`捕获所有外部变量）等。
- **parameters**：参数列表，与普通函数的参数列表类似。可以为空，表示不接受任何参数。
- **return-type**：返回类型。自C++14起，如果lambda体中只包含单一return语句，或者返回void，则可以省略返回类型，编译器会自动推导。
- **function-body**：函数体，定义了lambda表达式的行为。

- 值捕获：
- 引用捕获：
- 隐式捕获所有外部变量（以值方式）：
- 隐式捕获所有外部变量（以引用方式）：
*/

#include<iostream>
void test1() {
// 1. **基本示例**：

   auto f = []() { std::cout << "Hello, Lambda!" << std::endl; };
   f(); // 输出: Hello, Lambda!
   
}
void test2() {
// 2. **带参数的lambda表达式**：

   auto add = [](int x, int y) -> int { return x + y; };
   std::cout << add(2, 3) << std::endl; // 输出: 5
   
}
// 3. **捕获外部变量**：
void test3() {
//    - 值捕获：

     int x = 4;
     int y = 4;
     auto square = [x, &y]() { y+=1; return x * x; };
     std::cout << square() << std::endl; // 输出: 16
     std::cout << "&y=" << y << std::endl; // 输出: 16
     
}
void test4() {
//    - 引用捕获：

     int x = 4;
     auto double_it = [&x]() { x *= 2; };
     double_it();
     std::cout << x << std::endl; // 输出: 8
     
}
void test5() {
//    - 隐式捕获所有外部变量（以值方式）：

     int x = 4, y = 6;
     auto sum = [=]() { return x + y; };
     std::cout << sum() << std::endl; // 输出: 10
     
}
void test6() {
//    - 隐式捕获所有外部变量（以引用方式）：

     int x = 4, y = 6;
     auto modify = [&]() { x += 1; y += 1; };
     modify();
     std::cout << x << ", " << y << std::endl; // 输出: 5, 7
     
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
}