#include <iostream>
typedef int (*VaFunc_t)(...);

enum ERROR_CODE
{
    SUCCESS = 0,
    FAIL = -1
};

template <typename T, typename... Args>
class Tester
{
private:
    int mCurrentTestNum;
    VaFunc_t mCurrentTest;

public:
    Tester() = default;
    Tester(T func, int testCases);
    ~Tester();
    void TestRegisteredFunc(Args... args);
    static void TestFunc(T func, Args... args);
};

template <typename T, typename... Args>
Tester<T, Args...>::Tester(T func, int testCases)
{
    mCurrentTest = (VaFunc_t)func;
    mCurrentTestNum = 0;
}

template <typename T, typename... Args>
Tester<T, Args...>::~Tester()
{
}

template <typename T, typename... Args>
void Tester<T, Args...>::TestRegisteredFunc(Args... args)
{
    mCurrentTest(args...);
}

template <typename T, typename... Args>
void Tester<T, Args...>::TestFunc(T func, Args... args)
{

    switch (func(args...))
    {
    case SUCCESS:
        std::cout << "case Success";
        break;
    case FAIL:
        std::cout << "case end";
        break;
    default:
        std::cout << " i don't know ";
        break;
    }
}
