// 要在 C++ 中打印当前的文件名和行号，可以使用 `__FILE__` 和 `__LINE__`  [[[宏]]]  。


#include <iostream>

int main() {
    std::cout << "File: " << __FILE__ << std::endl;
    std::cout << "Line: " << __LINE__ << std::endl;

    return 0;
}


// 运行以上代码，将输出类似以下内容：


// File: 08_FILE_LINE.cpp
// Line: 8


// 这样可以获取当前源文件的文件名和行号，方便调试和定位问题。请注意，`__FILE__` 和 `__LINE__` 是预定义的宏，在编译时会被替换为对应的值。