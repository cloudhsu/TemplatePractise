template<typename T>
struct TypeParseTraits;

#define REGISTER_PARSE_TYPE(X) template <> struct TypeParseTraits<X> \
    { static const char* name; } ; const char* TypeParseTraits<X>::name = #X


REGISTER_PARSE_TYPE(int);
REGISTER_PARSE_TYPE(double);
REGISTER_PARSE_TYPE(FooClass);


int main(int argc, char *argv[])
{
    cout << TypeParseTraits<int>::name << endl;
    cout << TypeParseTraits<double>::name << endl;
    cout << TypeParseTraits<FooClass>::name << endl;
}