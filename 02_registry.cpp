#include <iostream>
#include <map>
using namespace std;

struct Employee
{
    string name;
    int age;
};

struct ClassFactory
{
    void create();
};

template<typename T>
struct Registry
{
    typedef std::map<std::string, T> Type;
    using Type2 = std::map<std::string, T>;
};

Registry<Employee>::Type employeeRoster;
Registry<void (*)(int)>::Type callbacks;
Registry<ClassFactory *>::Type factories;

int main(int argc, char *argv[])
{
    employeeRoster["cloud"] = Employee{"cloud", 40};
    employeeRoster["xd"] = Employee{"xd", 30};

    cout << employeeRoster["cloud"].name << endl;
    cout << employeeRoster["cloud"].age << endl;
    cout << employeeRoster["xd"].name << endl;
    cout << employeeRoster["xd"].age << endl;
}