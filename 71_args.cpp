// #include <iostream>

// // 定义一个模板函数
// template<typename T>
// void print(const T& value) {
//     std::cout << value << std::endl;
// }

// int main() {
//     // 调用模板函数
//     print(10);          // 打印整数
//     print(3.14);        // 打印浮点数
//     print("Hello!");    // 打印字符串

//     return 0;
// }

#include <iostream>

// 定义一个可变参数模板函数
template<typename... Args>
void printMultiple(Args... args) {
    (std::cout << ... << args) << std::endl;  // 使用折叠表达式进行参数展开
    /////////////////////
    // 71_args.cpp: In function 'void printMultiple(Args ...)':
    // 71_args.cpp:23:26: warning: fold-expressions only available with -std=c++17 or -std=gnu++17
    //      (std::cout << ... << args) << std::endl;  // 浣跨01;35m^~~~
}

int main() {
    // 调用可变参数模板函数
    printMultiple(10, 3.14, "Hello", 'A');

    return 0;
}