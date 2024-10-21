#include <stdio.h>
#include <stdarg.h>

// 可变参数函数
int sum(int count, ...) {
    va_list args;
    int total = 0;

    // 初始化可变参数列表
    va_start(args, count);

    // 遍历可变参数并计算总和
    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        total += value;
    }

    // 结束可变参数列表的使用
    va_end(args);

    return total;
}

int main() {
    int result = sum(4, 10, 20, 30, 40);
    printf("Sum: %d\n", result);

    return 0;
}