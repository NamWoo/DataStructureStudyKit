typedef int (*VaFunc)(...);



template <typename T, typename ...Args>
class Tester
{
private:
    int mCurrentTestNum;
public:
    Tester();
    ~Tester();

    static void TestVariadic(Args... arg, T evaluateValue);
};


template <typename ...Args>
Tester<Args...>::Tester()
{
}

template<typename ...Args>
Tester<Args...>::~Tester()
{
}

template<typename ...Args>
void Tester<Args...>::TestVariadic(Args...)
{
    VaFunc v(Args...);
}
