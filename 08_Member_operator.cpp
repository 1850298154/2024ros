// [[[ 成员  指针运算符]]]   的好处在于它允许在运行时动态地选择要调用的成员函数或成员变量，这对于某些场景非常有用。以下是一个具体的例子：

// 假设我们有一个游戏中的角色类，其中有很多不同的成员函数，例如攻击、防御、跳跃等。我们希望根据用户的输入  动态地  选择调用  不同的成员函数，实现不同的操作。

// 使用   成员函数指针   ，我们可以定义一个函数指针类型 `ActionPtr`，将其指向不同的成员函数，然后根据用户的输入选择相应的函数指针，来调用不同的成员函数。

#include <iostream>

class Character {
public:
    void attack() {
        std::cout << "Character attacks!" << std::endl;
    }
    void defend() {
        std::cout << "Character defends!" << std::endl;
    }
    void jump() {
        std::cout << "Character jumps!" << std::endl;
    }
};

int main() {
    Character character;
    typedef void (Character::*ActionPtr)(); // 定义成员函数指针类型
    typedef void (*PrintHelloHandle)(int); // 对比普通的函数指针

    ActionPtr actionPtr = nullptr; // 初始化指针为空

    int actionType = 2; // 假设用户输入了 2，要执行跳跃操作

    switch (actionType) {
        case 1:
            actionPtr = &Character::attack; // 将指针指向攻击函数
            break;
        case 2:
            actionPtr = &Character::jump; // 将指针指向跳跃函数
            break;
        case 3:
            actionPtr = &Character::defend; // 将指针指向防御函数
            break;
        default:
            break;
    }

    if (actionPtr != nullptr) { // 如果指针不为空，调用相应的成员函数
        (character.*actionPtr)();
    }

    return 0;
}


// 上述代码中，我们使用了成员函数指针来实现根据用户输入动态地选择要调用的成员函数。这种方式使得我们可以在运行时根据不同的条件选择调用不同的成员函数，非常灵活和方便。