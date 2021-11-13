#include <functional>

template<typename T>
class property
{
public:
    property(
        std::function<void(T)> setter,
        std::function<T()> getter) :
        setter_(setter), getter_(getter) { }
    operator T() const { return getter_(); }
    property<T> &operator= (const T &value) { setter_(value); return *this; }
    T &value() { return value_; }
private:
    std::function<void(T)> setter_;
    std::function<T()> getter_;
    T value_;
};

class person
{
public:
    property<int> age
    {
        [this](int x) { this->age.value() = x; },       // Setter ... yes you can do this!
        [this]() -> int {  return this->age.value(); }  // Getter.
    };
};

int main(int argc, char *argv[])
{
    person p;
    p.age = 20;
    int a = p.age;
    cout << "age:" << a << endl
}