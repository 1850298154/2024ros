// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
 
// int main()
// {
//     int n;
     
//     int a;
    
//     //以数组下标来存储随机数，下标对应的数组值为1，来说明是否是存储的随机数
//     while(~scanf("%d", &n))
//     {
//         int count[1001] = {0};
// 		int i;
//         for (i = 0; i < n; i++)
//         {
//             scanf("%d", &a);
//             count[a] = 1;
//         }
//         for (i = 0; i < 1001; i++)
//         {
//             if (count[i] == 1)
//             {
//                 printf("%d\n", i);
//             }
//         }
//     }
     
//     return 0;
// }



























/*
本文系「人工智能安全」（微信公众号）原创，转载请联系本文作者（同博客作者）。
欢迎你转发分享至朋友圈，并给予「关注、星标、点赞」三连支持。互相欣赏，互相批判。
我是一名有诗人气质的网络安全工程师
期待与你的思想交流碰撞出智慧的花火
水木清华
2020-03-12
明明的随机数
*/
#include <iostream>
using namespace std;
//有序数组的接口
int RankedArray(int n)
{
    int random_num; //输入随机数
    //初始化一个数组，用于表示随机数集合中的元素（某个0~1000之间的随机整数）的有无情况
    int a[1001] = {0};
    //连续输入 n 个随机整数
    while (n--)
    {
        cin >> random_num;
        //数组的下标等于输入的随机整数，下标对应的元素为 1 表示该随机整数存在
        a[random_num] = 1;
    }
    //按从小到大的顺序，依次输出随机数集合（数组）中所包含的随机整数
    for (int i = 0; i < 1001; i++)
    {
        if (a[i] == 1)
        {
            cout << i << endl;
        }
    }
    return 0;
}
//主函数
int main()
{
    int n; //输入随机数的个数

    std::istream  ret = (cin >> n);
    while(cin >> n)
    {
        RankedArray(n); //调用有序数组的接口
    }
    return 0;
}