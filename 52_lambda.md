C++中的lambda表达式是一种方便快捷地定义匿名函数的方式，自C++11起引入，广泛用于算法、事件处理等场合。Lambda表达式可以捕获作用域中的变量，并拥有自己的参数和返回类型。其基本语法如下：

```cpp
[ capture ] ( parameters ) -> return-type {
    function-body
}
```

- **capture**：捕获列表，定义了lambda表达式可以访问的外部变量。可以为空，或者捕获一个或多个变量。捕获方式有值捕获（`=`或明确指定变量名）、引用捕获（`&`）、隐式捕获（`=`或`&`捕获所有外部变量）等。
- **parameters**：参数列表，与普通函数的参数列表类似。可以为空，表示不接受任何参数。
- **return-type**：返回类型。自C++14起，如果lambda体中只包含单一return语句，或者返回void，则可以省略返回类型，编译器会自动推导。
- **function-body**：函数体，定义了lambda表达式的行为。

### 示例

1. **基本示例**：
   ```cpp
   auto f = []() { std::cout << "Hello, Lambda!" << std::endl; };
   f(); // 输出: Hello, Lambda!
   ```

2. **带参数的lambda表达式**：
   ```cpp
   auto add = [](int x, int y) -> int { return x + y; };
   std::cout << add(2, 3) << std::endl; // 输出: 5
   ```

3. **捕获外部变量**：
   - 值捕获：
     ```cpp
     int x = 4;
     auto square = [x]() { return x * x; };
     std::cout << square() << std::endl; // 输出: 16
     ```
   - 引用捕获：
     ```cpp
     int x = 4;
     auto double_it = [&x]() { x *= 2; };
     double_it();
     std::cout << x << std::endl; // 输出: 8
     ```
   - 隐式捕获所有外部变量（以值方式）：
     ```cpp
     int x = 4, y = 6;
     auto sum = [=]() { return x + y; };
     std::cout << sum() << std::endl; // 输出: 10
     ```
   - 隐式捕获所有外部变量（以引用方式）：
     ```cpp
     int x = 4, y = 6;
     auto modify = [&]() { x += 1; y += 1; };
     modify();
     std::cout << x << ", " << y << std::endl; // 输出: 5, 7
     ```

Lambda表达式在STL算法、异步编程、事件处理等领域非常有用，因为它们允许在需要传递函数作为参数的地方，以简洁的方式直接定义函数行为。