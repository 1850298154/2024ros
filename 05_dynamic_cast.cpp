#include <iostream>

class Animal {
public:
    virtual void move() {
        std::cout << "Animal is moving." << std::endl;
    }
};

class Dog : public Animal {
public:
    void move() override {
        std::cout << "Dog is running." << std::endl;
    }
    void bark() {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void move() override {
        std::cout << "Cat is walking." << std::endl;
    }
    void meow() {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animal = new Dog();
    animal->move();

    // 使用 dynamic_cast 将 Animal 类型的指针转换为 Dog 类型的指针
    Dog* dog = dynamic_cast<Dog*>(animal);
    if (dog) {
        dog->bark();
    }

    Animal& animalRef = *new Cat();
    animalRef.move();

    // 使用 dynamic_cast 将 Animal 类型的引用转换为 Cat 类型的引用
    Cat& catRef = dynamic_cast<Cat&>(animalRef);
    if (&catRef == &animalRef) {
        std::cout << "Same reference" << std::endl;
    }
    catRef.meow();

    return 0;
}
