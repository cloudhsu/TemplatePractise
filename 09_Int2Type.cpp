template<int v> struct Int2Type
{
    enum {value = v};
};

template<class T, bool isPolymorphic> class MyContainer
{
private:
    void function(T *p, Int2Type<true>)
    {
        T *p2 = p->clone();
    }
    void function(T *p, Int2Type<false>)
    {
        T *p2 = new T(*p);
    }
public:
    void function(T *p)
    {
        function(p, Int2Type<isPolymorphic>());
    }
};