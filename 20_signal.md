20_signal

`#include <signal.h>` 是 C/C++ 中用于处理信号的头文件。信号是在软件中发生的某些事件，如用户按下终止键（Ctrl+C）或发生错误等。

通过使用 `<signal.h>` 头文件提供的函数和宏，我们可以捕捉、处理和发送信号。

以下是一些常用的信号处理函数和宏：

1. `void (*signal(int sig, void (*func)(int)))(int)`：设置信号处理函数。可以使用此函数将自定义的处理函数与指定的信号关联起来。

2. `int raise(int sig)`：向进程发送指定的信号。

3. `SIG_DFL`：默认信号处理函数的宏，用于恢复信号的默认处理方式。

4. `SIG_IGN`：忽略信号的宏，用于忽略指定的信号。

下面是一个简单示例，展示了如何使用 `<signal.h>` 头文件中的函数和宏来处理信号：

```cpp
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
```

上述代码中，我们使用 `signal()` 函数将自定义的信号处理函数 `signalHandler()` 与 `SIGINT` 信号（即终止信号）关联起来。当用户按下终止键（Ctrl+C）时，会触发 `SIGINT` 信号，并调用 `signalHandler()` 函数进行处理。

注意：不同的操作系统和编译器可能对信号处理有所不同，因此在实际使用中需要根据目标平台和编译环境进行适当的调整。


# 解释 

/* Type of a signal handler.  */
typedef void (*__sighandler_t) (int);

/* Set the handler for the signal SIG to HANDLER, returning the old
   handler, or SIG_ERR on error.
   By default `signal' has the BSD semantic.  */
#ifdef __USE_MISC
extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __THROW;
#else


void (
    *signal(
            int sig, 
            void (*func)(int)
        )
) (int);

这是C++语言中signal函数的声明，它的
    返回值是一个指向 *函数的指针*  ，
    该指针指向的函数的 
        参数为      *int类型*
        并返回      *void类型* 。

signal函数的作用是在接收到指定信号(sig)时，调用指定函数(func)来处理该信号。这个函数可以自定义，一般用于处理程序中断或异常等情况。

函数的声明中，signal是函数名，int sig和void (*func)(int)是函数的参数，其中sig表示要处理的信号，func表示当接收到信号时要回调的函数。

在函数体内部，首先声明了一个指向函数的指针p，它的参数为int类型，返回值为void类型。接着调用signal函数，并将sig和func作为参数传递进去。signal函数执行后会返回一个指向函数的指针，将其赋值给p，最后将p作为整个函数的返回值返回。

因此，这个函数的作用是注册一个信号处理函数，并返回这个处理函数的指针。调用这个函数的时候，需要传入两个参数：信号编号和信号处理函数的指针。