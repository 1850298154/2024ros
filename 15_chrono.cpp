// #include <chrono> 是 C++ 标准库中的头文件，提供了时间相关的功能。
// 使用方式如下：

/*
H:\vs_Community\项目管理\练习\cpp速成\速成c++面向对象\cpp面向对象-补充\2024ros>.\a.exe
执行时间：4 毫秒
￿
*/

#include <iostream>
#include <chrono>


#include <iostream> //_fileno(stdout)  wcout endl
#include <io.h>  // _setmode
#include <fcntl.h> // _O_U8TEXT 

int main() {
    // 设置输出流编码为UTF-8
    _setmode(_fileno(stdout), _O_U8TEXT);

    // 获取当前时间点
    auto start = std::chrono::high_resolution_clock::now();
    
    // 执行一些需要测量时间的操作
    for (int i = 0; i < 1000000; ++i) {
        // do something
    }
    
    // 获取操作结束后的时间点
    auto end = std::chrono::high_resolution_clock::now();
    
    // 计算执行时间（以毫秒为单位）
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    // 输出执行时间
    std::wcout << L"执行时间：" << duration << L" 毫秒" << std::endl;
    std::wcout << "执行时间：" << duration << " 毫秒" << std::endl;
    std::cout << "执行时间：" << duration << " 毫秒" << std::endl;
    
    return 0;
}

/*

以上代码演示了如何使用 `<chrono>` 来测量一段代码的执行时间。
首先，通过 `std::chrono::high_resolution_clock::now()` 获取当前时间点作为起始点，
然后执行需要测量时间的操作，再次调用 `std::chrono::high_resolution_clock::now()` 获取结束时间点。
最后，通过 `std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()` 计算起始点和结束点之间的时间差，并将结果转换成毫秒。

请注意，`<chrono>` 头文件提供了多种时间类型和操作，可以根据具体需求选择合适的类型和函数。
上述代码中使用的是高分辨率时钟 `std::chrono::high_resolution_clock` 和毫秒 `std::chrono::milliseconds`。
*/
