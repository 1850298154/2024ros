#include <iostream>
#include <string>
using namespace std;

int main()
{
    try {
        string str = "Hello, world!";
        string sub = str.substr(13, 10);  // 从索引 13 开始提取长度为 10 的子字符串
        cout << sub << endl;
    } catch (const out_of_range& oor) {
        // cerr << "Out of Range error: " << oor.what() << endl;
        cout << "Out of Range error: " << oor.what() << endl;
    }
    cout << "Out of Range error: " << endl;

    // 输出：Out of Range error: basic_string::substr: __pos (which is 13) > this->size() (which is 13)
    
    string str;
    while (cin >> str)
    {




        // 补0
        int len = str.size();
        if (len % 8 != 0)
        {
            int count = 8 - len % 8;
            str.append(count, '0');
        }

        // 按格式输出
        int newLen = str.size();
        for (int i = 0; i < newLen; i += 8)
        {
            cout << str.substr(i, 8) << endl;
        }
    }
    return 0;
}