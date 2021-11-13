#include <iostream>
using namespace std;

class RealBase
{
public:
    int code_base() {return 1;}
};

template<class TExtends = void>
class CRTPBase : public RealBase
{
public:
};

class QTExtend : public CRTPBase<QTExtend>
{
public:
    int code_qt() {return 2;}
};

class Win32Extend : public CRTPBase<Win32Extend>
{
public:
    int code_win32() {return 3;}
};

int main()
{
    RealBase r;
    cout << r.code_base() << endl;
    cout << "--------------------------" << endl;
    QTExtend qt;
    cout << qt.code_base() << endl;
    cout << qt.code_qt() << endl;
    cout << "--------------------------" << endl;
    Win32Extend win32;
    cout << win32.code_base() << endl;
    cout << win32.code_win32() << endl;

    return 0;
}