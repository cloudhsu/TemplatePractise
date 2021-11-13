// how to function partial specilizarion

struct Widget {};

template<class T, class U> T *create(const U &arg)
{
    return new T(arg);
}

template<class U>
Widget *create<Widget, U>(const U &arg)   // compile error: function template partial specialization is not allowed
{
    return new Widget(arg, -1);
}
// using overloading tp simulate function partial specilizarion
template<class T, class U>
T *create(const U &arg, T)
{
    return new T(arg);
}
template<class U>
Widget *create(const U &arg, Widget)
{
    return new Widget(arg, -1);
}
