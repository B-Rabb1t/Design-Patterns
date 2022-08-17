#include <iostream>

class MyClass
{
    class Impl
    {
        std::string name;

    public:
        Impl(std::string name) : name(name) {}

        void Function1()
        {
            std::cout << name << " Running function1\n";
        }

        void Function2()
        {
            std::cout << "Running function2\n";
        }
    };
    Impl *impl;

public:
    MyClass(std::string name) : impl(new Impl(name)) {}
    ~MyClass()
    {
        delete impl;
    }

    void Function1()
    {
        impl->Function1();
    }

    void Function2()
    {
        impl->Function2();
    }
};

int main()
{
    MyClass myclass("Indirectly");

    myclass.Function1();
    myclass.Function2();
}