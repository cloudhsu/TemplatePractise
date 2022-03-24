// C++ 17

#include <type_traits>

enum class Animal { Cat, Dog, Horse };

template <typename EnumClass, EnumClass EnumVal>
void magic_impl()
{
    static_assert(std::is_same_v<EnumClass, Animal>);
    static_assert(EnumVal == Animal::Cat);
}

template <auto EnumVal>
void magic()
{
    magic_impl<decltype(EnumVal), EnumVal>();
}

int main()
{
    magic<Animal::Cat>();
}