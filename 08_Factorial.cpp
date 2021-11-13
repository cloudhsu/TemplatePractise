#include <iostream>
using namespace std;

template <int n>
struct Fact
{
    enum { value = n * Fact < n - 1 >::value };
};

template <>
struct Fact<1>
{
    enum { value = 1 };
};

int main()
{
    cout << Fact<5>::value << endl;

    return 0;
}