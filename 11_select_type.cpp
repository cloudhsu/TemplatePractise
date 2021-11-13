template <bool flag, typename T, typename U>
struct Select
{
	typedef T Result;
};
template<typename T, typename U>
struct Select<false, T, U>
{
	typedef U Result;
};

template <typename T, bool isPolymorphic>
class MyContainer
{
	typedef typename Select<isPolymorphic, T*, T>::Result ValueType;
	std::vector<ValueType> objects;

};