#include <iostream>
#include <csignal>

// 自定义的信号处理函数
void signalHandler(int signum) {
    std::cout << "Received signal: " << signum << std::endl;
}

int main() {
    // 设置自定义的信号处理函数
    signal(SIGINT, signalHandler);

    std::cout << "Running..." << std::endl;

    // 无限循环，等待信号
    while (true) {}

    return 0;
}


void (
    *signal_ret(
            int sig, 
            void (*func)(int)
        )
) (int);
