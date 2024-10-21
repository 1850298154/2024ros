在 C++ 中，所有函数的参数都必须有确定的类型，C++ 不支持像 Python 那样的动态类型系统。然而，如果你希望编写与类型无关的代码，可以使用模板（templates）。模板允许你编写泛型代码，这样可以在编译时根据实际传递的参数类型生成具体的实现。

这里是一个简单的模板函数的例子：

```cpp
#include <iostream>

// 定义一个模板函数
template<typename T>
void print(const T& value) {
    std::cout << value << std::endl;
}

int main() {
    // 调用模板函数
    print(10);          // 打印整数
    print(3.14);        // 打印浮点数
    print("Hello!");    // 打印字符串

    return 0;
}
```

在这个例子中，`print` 函数是一个模板函数，它可以接受不同类型的参数。`template<typename T>` 声明了一个模板，其中 `T` 是一个类型参数。在调用 `print` 函数时，编译器会根据传递的参数类型推导出 `T` 的具体类型。

如果你需要一个函数可以接受多个不同类型的参数，也可以使用可变参数模板：

```cpp
#include <iostream>

// 定义一个可变参数模板函数
template<typename... Args>
void printMultiple(Args... args) {
    (std::cout << ... << args) << std::endl;  // 使用折叠表达式进行参数展开
}

int main() {
    // 调用可变参数模板函数
    printMultiple(10, 3.14, "Hello", 'A');

    return 0;
}
```

在这个例子中，`printMultiple` 是一个可变参数模板函数，它可以接受任意数量和类型的参数。`Args...` 表示模板参数包，而 `args...` 表示函数参数包。折叠表达式 `(std::cout << ... << args)` 用于展开并打印所有参数。

通过使用模板和可变参数模板，你可以编写更加灵活和通用的函数，而不需要明确指定参数类型。