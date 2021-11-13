#include <iostream>
using namespace std;

struct QString
{
    QString(string _a, int _b) : a(_a), b(_b) {}
    string a;
    int b;
};

struct LPSTR
{
    LPSTR(string _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
    string a;
    int b;
    int c;
};

struct TypeSelect
{
    enum Platform { CPP, QT, Win32};
};

template<TypeSelect::Platform>
struct CBTypeCollect
{
};

template<>
struct CBTypeCollect<TypeSelect::CPP>
{
    using CBString = string;
};

template<>
struct CBTypeCollect<TypeSelect::QT>
{
    using CBString = QString;
};

template<>
struct CBTypeCollect<TypeSelect::Win32>
{
    using CBString = LPSTR;
};

struct CBTypeCPP : CBTypeCollect<TypeSelect::CPP>
{

};

struct CBTypeQT : CBTypeCollect<TypeSelect::QT>
{

};

struct CBTypeWin32 : CBTypeCollect<TypeSelect::Win32>
{

};


class test
{
public:
    static CBTypeCPP::CBString getData1() { return string("abc"); }
    static CBTypeQT::CBString getData2() { return {"def", 1}; }
    static CBTypeWin32::CBString getData3() { return {"abcde", 12, 13}; }
};

int main()
{
    cout << test::getData1() << endl;

    cout << test::getData2().a << endl;
    cout << test::getData2().b << endl;

    cout << test::getData3().a << endl;
    cout << test::getData3().b << endl;
    cout << test::getData3().c << endl;

    return 0;
}