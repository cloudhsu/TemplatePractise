#include <iostream>

struct BasicCoffee
{
    void print() {std::cout << "Coffee!\n";}
};

template <class T>
struct CreamDecorator
{
    CreamDecorator(T x) : mNested(x) {}

    void print() {mNested.print(); std::cout << "..with cream!\n";}
    T mNested;
};

template <class T>
struct SugarDecorator
{
    SugarDecorator(T x) : mNested(x) {}

    void print() {mNested.print(); std::cout << "..with sugar!\n";}
    T mNested;
};

template <class T>
CreamDecorator<T> addCream(T x) {return CreamDecorator<T>(x);}

template <class T>
SugarDecorator<T> addSugar(T x) {return SugarDecorator<T>(x);}

int main()
{
    auto myCoffee = addSugar(addCream(BasicCoffee()));
    myCoffee.print();
    return 0;
}