#include <iostream>
#include <iomanip>  
// manipulate

using namespace std;
#define PI 3.14159265358979323846

int main() {
/*
在C++中，float类型通常占用4个字节（32位），能够表示的有效数字大约是  7位  左右；double类型通常占用8个字节（64位），能够表示的有效数字大约是  15位  左右。

具体的精度限制取决于计算机的硬件和操作系统等因素，不同的计算机可能会有不同的精度限制。但一般来说，float和double类型都能够满足大部分实际应用的需求。如果需要更高精度的计算，可以考虑使用第三方库或自行实现高精度算法。
*/
    float  y = 3.14159265358979323846;
    double x = 3.14159265358979323846;
    //         12345678901234567
    //         1234567890123456789012

    cout << setprecision(20) << x << endl;
    cout << setprecision(30) << x << endl;
    cout << "3.14159265358979323846" << endl << endl;
    cout << "1234567890123456789012" << endl << endl;

    cout << setprecision(20) << y << endl;
    cout << setprecision(30) << y << endl;
    cout << "1234567890123456789012" << endl << endl;
    cout << "3.14159265358979323846" << endl << endl;

    cout << setprecision(20) << PI << endl;
    cout << setprecision(30) << PI << endl;
    cout << "1234567890123456789012" << endl << endl;
    cout << "3.14159265358979323846" << endl << endl;
    return 0;
}
