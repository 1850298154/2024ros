/*
C20特性自GCC 8起可用。
要启用C20支持，请添加命令行参数
-std=c++20
适用于G++ 9及以后版本
-std=c++2a
或者，要启用除C++20功能之外的GNU扩展，请添加
-std=gnu++20


H:\vs_Community\项目管理\练习\cpp速成\速成c++面向对象\cpp面向对象-补充\2024ros>g++  -std=c++2a  18_string.cpp
18_string.cpp:16:15: warning: multi-character character constant [-Wmultichar]
     auto m0 = 'abcd'; // int, value 0x61626364      
               ^~~~~~

H:\vs_Community\项目管理\练习\cpp速成\速成c++面向对象\cpp面向对象-补充\2024ros>


H:\vs_Community\项目管理\练习\cpp速成\速成c++面向对象
\cpp面向对象-补充\2024ros>.\a.exe
A
A
65
65
65
61626364
61626364
1633837924
hello
hello
0x407006
0x407006
0x407014
"Hello \ world"
"Hello \ world"
0x407040
0x407040
0x407060
hello
hello
"Hello \ world"
"Hello \ world"

*/ 

#include <string>
using namespace std::string_literals; // enables s-suffix for std::string literals
#include <iostream>
using namespace std;

int main()
{
    // Character literals
    auto c0 =   'A'; // char
    auto c1 = u8'A'; // char
    auto c2 =  L'A'; // wchar_t
    auto c3 =  u'A'; // char16_t
    auto c4 =  U'A'; // char32_t

    cout << c0 << endl;
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << c4 << endl;


    // Multicharacter literals
    auto m0 = 'abcd'; // int, value 0x61626364
    cout << std::hex << m0 << endl;
    cout <<             m0 << endl;
    cout << std::dec << m0 << endl;

    // String literals
    auto s0 =   "hello"; // const char*
    auto s1 = u8"hello"; // const char* before C++20, encoded as UTF-8,
                         // const char8_t* in C++20
    auto s2 =  L"hello"; // const wchar_t*
    auto s3 =  u"hello"; // const char16_t*, encoded as UTF-16
    auto s4 =  U"hello"; // const char32_t*, encoded as UTF-32

    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;


    // Raw string literals containing unescaped \ and "
    auto R0 =   R"("Hello \ world")"; // const char*
    auto R1 = u8R"("Hello \ world")"; // const char* before C++20, encoded as UTF-8,
                                      // const char8_t* in C++20
    auto R2 =  LR"("Hello \ world")"; // const wchar_t*
    auto R3 =  uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16
    auto R4 =  UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32

    cout << R0 << endl;
    cout << R1 << endl;
    cout << R2 << endl;
    cout << R3 << endl;
    cout << R4 << endl;

    // using namespace std::string_literals; // enables s-suffix for std::string literals

    // Combining string literals with standard s-suffix
    auto S0 =   "hello"s; // std::string
    auto S1 = u8"hello"s; // std::string before C++20, std::u8string in C++20
    auto S2 =  L"hello"s; // std::wstring
    auto S3 =  u"hello"s; // std::u16string
    auto S4 =  U"hello"s; // std::u32string

    // Combining raw string literals with standard s-suffix
    auto S5 =   R"("Hello \ world")"s; // std::string from a raw const char*
    auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char* before C++20, encoded as UTF-8,
                                       // std::u8string in C++20
    auto S7 =  LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*
    auto S8 =  uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16
    auto S9 =  UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32

    cout << S0 << endl;
    cout << S1 << endl;
    // cout << S2 << endl;
    // cout << S3 << endl;
    // cout << S4 << endl;
    cout << S5 << endl;
    cout << S6 << endl;
    // cout << S7 << endl;
    // cout << S8 << endl;
    // cout << S9 << endl;


}