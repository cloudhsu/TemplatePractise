#include <iostream>
using namespace std;

template <typename F0, typename... F>
class Composer2
{
    F0 f0_;
    Composer2<F...> tail_;
public:
    Composer2(F0 f0, F... f) : f0_(f0), tail_(f...) {}

    template <typename T>
    T operator()(const T &x) const
    {
        return f0_(tail_(x));
    }
};

template <typename F>
class Composer2<F>
{
    F f_;
public:
    Composer2(F f) : f_(f) {}

    template <typename T>
    T operator()(const T &x) const
    {
        return f_(x);
    }
};

template <typename... F>
Composer2<F...> compose2(F... f)
{
    return Composer2<F...>(f...);
}

int f(int x)
{
    cout << "f" << endl;
    return x + 1;
}
int g(int x)
{
    cout << "g" << endl;
    return x * 2;
}
int h(int x)
{
    cout << "h" << endl;
    return x - 1;
}

int main()
{
    std::cout << compose2(f, g, h)(42) << endl;
    return 0;
}
