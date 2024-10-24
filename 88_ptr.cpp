#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass Constructor" << std::endl; }
    ~MyClass() { std::cout << "MyClass Destructor" << std::endl; }
};

int main() {
    std::shared_ptr<MyClass> ptr1(new MyClass());
    std::weak_ptr<MyClass> weakPtr = ptr1; // 创建 weak_ptr

    std::cout << "Reference Count: " << ptr1.use_count() << std::endl; // 输出引用计数

    if (auto sharedPtr = weakPtr.lock()) { // 尝试升级
        std::cout << "Resource is still alive." << std::endl;
    } else {
        std::cout << "Resource has been deleted." << std::endl;
    }

    ptr1.reset(); // 释放资源
    if (auto sharedPtr = weakPtr.lock()) {
        std::cout << "Resource is still alive." << std::endl;
    } else {
        std::cout << "Resource has been deleted." << std::endl; // 资源已被删除
    }

    return 0;
}
