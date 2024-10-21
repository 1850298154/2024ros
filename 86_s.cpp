#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char buffer[50] = {0};  // 大小根据需要调整
    int num = 789;
    sprintf(buffer, "%d", num);
    for (int i=0; i<50; i++) {
        cout << i << ":" << buffer[i] << endl;
    }
    std::string str(buffer);

}