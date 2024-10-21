#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "This is the base class." << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "This is the derived class." << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();  // 派生类指针赋值给基类指针
    // Base* basePtr = new Base();  
    basePtr->print();  // 调用派生类的成员函数

    Derived* derivedPtr = static_cast<Derived*>(basePtr);  // 基类指针转换为派生类指针
    derivedPtr->print();  // 调用派生类的成员函数

    delete basePtr;  // 释放内存
    return 0;
}
