#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(int, char **)
{
    string s;
    char c;
    getline(cin, s) >> c;

    unordered_map<char, size_t> unorderedMap;
    for (auto i : s) {
        ++unorderedMap[tolower(i)];
    }
    cout << unorderedMap[tolower(c)] << endl;
}
