<!-- 
```((.|\n)*?```)
```cpp$1 
-->
#  多态、覆写、重写

多态（Polymorphism）是指同一个方法可以被不同的对象调用，并且产生不同的结果，这种机制可以提高代码的复用性和可扩展性。

覆写（Override）和重写（Overload）都是指在子类中重新定义父类的方法。但两者的区别在于：覆写是指在子类中重新定义与父类方法名、参数类型、返回类型均相同的方法；而重载则是指在同一类中定义多个方法，它们具有相同的方法名，但参数类型、个数或顺序不同。

举个例子，假设有一个Animal类，其中有一个makeSound()方法：

```cpp
public class Animal {
    public void makeSound() {
        System.out.println("The animal makes a sound");
    }
}
```

然后我们派生出一个Cat类，覆写makeSound()方法：

```cpp
public class Cat extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Meow");
    }
}
```

现在我们创建一个Animal类型的变量a和一个Cat类型的变量c，并分别调用它们的makeSound()方法：

```cpp
Animal a = new Animal();
Cat c = new Cat();

a.makeSound();  // 输出 "The animal makes a sound"
c.makeSound();  // 输出 "Meow"
```

由于多态的存在，我们可以通过Animal类型的变量来调用Cat类的makeSound()方法，这就是多态的体现。同时，由于Cat类覆写了Animal类的makeSound()方法，因此Cat类型的变量调用makeSound()方法时，会执行Cat类中的实现，这就是覆写的体现。

#  C++覆写、重写、重载，三个对应的单词以及具体代码例子


在C++中，覆写（override）、重写（overwrite）和重载（overload）是面向对象编程中常用的概念。
override 、overwrite  
覆盖、改写

1. 覆写（override）：
   - 对应的单词：override
   - 作用：子类重新定义父类中的虚函数，实现多态性。
   - 代码例子：

     ```cpp
     class Animal {
     public:
         virtual void makeSound() {
             cout << "Animal makes a sound." << endl;
         }
     };

     class Dog : public Animal {
     public:
         void makeSound() override {
             cout << "Dog barks." << endl;
         }
     };
     ```

2. 重写（overwrite）：
   - 对应的单词：overwrite
   - 作用：子类重新定义父类中的非虚函数，隐藏父类的同名函数。
   - 代码例子：

     ```cpp
     class Shape {
     public:
         void printInfo() {
             cout << "This is a shape." << endl;
         }
     };

     class Rectangle : public Shape {
     public:
         void printInfo() {
             cout << "This is a rectangle." << endl;
         }
     };
     ```

3. 重载（overload）：
   - 对应的单词：overload
   - 作用：在同一个作用域内，根据参数的不同，实现多个同名函数。
   - 代码例子：

     ```cpp
     class Calculator {
     public:
         int add(int a, int b) {
             return a + b;
         }

         double add(double a, double b) {
             return a + b;
         }
     };
     ```

以上是覆写、重写和重载的三个对应单词及其具体的代码例子。请注意，这些例子仅供参考，并不涵盖所有可能的情况。





#  C++覆写、重写、重载、重定义，对应的单词以及具体代码例子

在C++中，覆写（override）、重写（overwrite）、重载（overload）、重定义（redefine）是几个常用的概念。以下是它们对应的单词和具体的代码例子：

1. 覆写（override）：
   - 单词：override
   - 作用：在派生类中重新实现基类的虚函数
   - 代码例子：

     ```cppcpp
     class Base {
     public:
         virtual void foo() {
             cout << "Base::foo()" << endl;
         }
     };

     class Derived : public Base {
     public:
         void foo() override {   // 使用override关键字进行覆写
             cout << "Derived::foo()" << endl;
         }
     };
     ```

2. 重写（overwrite）：
   - 单词：overwrite
   - 作用：在派生类中重新实现基类的非虚函数
   - 代码例子：

     ```cppcpp
     class Base {
     public:
         void bar() {
             cout << "Base::bar()" << endl;
         }
     };

     class Derived : public Base {
     public:
         void bar() {   // 在派生类中重写基类的非虚函数
             cout << "Derived::bar()" << endl;
         }
     };
     ```

3. 重载（overload）：
   - 单词：overload
   - 作用：在同一个作用域内，根据函数参数的不同提供多个具有相同名称但参数类型或个数不同的函数
   - 代码例子：

     ```cppcpp
     class MyClass {
     public:
         void func(int num) {
             cout << "func(int): " << num << endl;
         }

         void func(double num) {
             cout << "func(double): " << num << endl;
         }
     };
     ```

4. 重定义（redefine）：
   - 单词：redefine
   - 作用：在同一个作用域内，重新定义已有的函数或变量
   - 代码例子：

     ```cppcpp
     void func() {
         cout << "Original func()" << endl;
     }

     void func() {   // 重定义已有的函数
         cout << "Redefined func()" << endl;
     }
     ```

以上是C++中覆写、重写、重载、重定义对应的单词和代码例子。请注意，在实际编程中，要根据具体情况选择使用适当的概念和技术。



#  C++覆写、重写、重载，都分别怎么访问父类的

在C++中，覆写（override）、重写（overwrite）和重载（overload）是面向对象编程中常用的概念。它们分别表示不同的行为和目的。

1. 覆写（override）：
   覆写是指在派生类中重新实现基类的虚函数。通过覆写，派生类可以对基类的方法进行修改或添加新的实现逻辑，以满足派生类的需求。派生类中的覆写函数必须具有相同的函数原型、函数名和返回类型。

   在派生类中访问父类的方法时，可以使用作用域解析运算符`::`来显式指定要调用的父类方法。例如，`Base::functionName()`表示调用基类的`functionName()`方法。

2. 重写（overwrite）：
   重写是指在派生类中重新实现基类的非虚函数。与覆写不同，重写函数不需要在基类中声明为虚函数。重写函数的名称、参数列表和返回类型必须与基类中的函数相同。

   在派生类中访问父类的方法时，可以使用作用域解析运算符`::`来显式指定要访问的父类方法。例如，`Base::functionName()`表示访问基类的`functionName()`方法。

3. 重载（overload）：
   重载是指在同一个作用域中定义多个具有相同名称但参数列表不同的函数。重载的目的是为了提供更多的函数调用方式，以适应不同的参数类型和个数。

   在重载函数中，无需显式指定访问父类方法，因为重载函数与基类的方法没有直接的继承关系。每个重载函数都是独立的，根据调用时提供的参数类型和个数来决定调用哪个函数。

总结：
- 覆写（override）和重写（overwrite）都是指在派生类中重新实现基类的方法，可以使用作用域解析运算符`::`来访问父类方法。
- 重载（overload）是指在同一个作用域中定义多个具有相同名称但参数列表不同的函数，无需显式指定访问父类方法。