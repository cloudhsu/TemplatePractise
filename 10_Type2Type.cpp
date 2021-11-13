#include <iostream>
#include <string>
using namespace std;


struct Widget
{
    Widget() = default;
    Widget(const string arg, int iArg) : name(arg) {}
    string name;
};

template<typename T>
struct Type2Type
{
    typedef T OriginalType;
};

template<class T, class U>
T *create(const U &arg, Type2Type<T>)
{
    return new T(arg);
}

template<class U>
Widget *create(const U &arg, Type2Type<Widget>)
{
    return new Widget(arg, -1);
}

int main()
{
    string *ps = create("HelloString", Type2Type<string>());
    Widget *pw = create("HelloWidget", Type2Type<Widget>());

    cout << *ps << endl;
    cout << pw->name << endl;

    return 0;
}