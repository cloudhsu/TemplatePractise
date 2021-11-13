#include <iostream>
using namespace std;

// class Base
// {
// public:
// 	virtual void print() = 0;
// };

template<class TBase>
class Derive1 : public TBase
{
public:
	void print()
	{
		cout << "d1" << endl;
		TBase::print();
	}
};

template<class TBase>
class Derive2 : public TBase
{
public:
	void print()
	{
		cout << "d2" << endl;
		TBase::print();
	}
};

class HostClass
{
public:
	void print()
	{
		cout << "host" << endl;
	}
};

class Host2Class
{
public:
	void print2()
	{
		cout << "host" << endl;
	}
};


int main()
{
	HostClass h;
	h.print();
	cout << "----------------------" << endl;
	Derive1<HostClass> d1;
	d1.print();
	cout << "----------------------" << endl;
	Derive1<Host2Class> d12;
	d12.print();                    // compile error: in instantiation of member function
	cout << "----------------------" << endl;
	Derive2<HostClass> d2;
	d2.print();
	cout << "----------------------" << endl;
	Derive1<Derive2<HostClass>> dd1;
	dd1.print();
	cout << typeid(dd1).name() << endl;
	cout << "----------------------" << endl;
	return 0;
}