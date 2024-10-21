/*
出现乱码的原因可能是编码问题，可以尝试修改输出流的编码方式。以下是一个简单的示例代码：


https://learn.microsoft.com/zh-cn/cpp/cpp/string-and-character-literals-cpp?view=msvc-170


*/
#include <iostream> //_fileno(stdout)  wcout endl
#include <io.h>  // _setmode
#include <fcntl.h> // _O_U8TEXT 

int main() {
    // 设置输出流编码为UTF-8
    _setmode(_fileno(stdout), _O_U8TEXT);
    
    // 输出中文字符串
    std::wcout << L"执行时间： \nAM08:00" << std::endl;
    std::wcout << u"执行时间： \nAM08:00" << std::endl;
    std::wcout << "执行时间： \nAM08:00" << std::endl;
    
    return 0;
}
/*

以上代码中，通过 
`_setmode` 函数将输出流的编码方式设置为 UTF-8，
然后使用 `std::wcout` 输出中文字符串。

请注意，
使用 Unicode 编码时需要
在字符串前面加上 `L` 前缀。
另外，如果编译器不支持 C++11 及以上版本的话，
可以用 `wprintf` 或 `fwprintf` 等函数来输出宽字符。

*/