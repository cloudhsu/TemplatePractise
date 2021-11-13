template <typename T>
class CBSingleton
{
protected:
    CBSingleton() = default;
    ~CBSingleton() = default;
public:

    static T& instance()
    {
        static T instance;
        return instance;
    }

private:
    CBSingleton(const CBSingleton&)= delete;
    CBSingleton& operator=(const CBSingleton&)= delete;
};

class Test : public CBSingleton<Test>
{
    friend class CBSingleton<Test>;
public:
    void print()
    {
        cout<<"test"<<endl;
    }
};

void main()
{
    Test::instance().print();
}