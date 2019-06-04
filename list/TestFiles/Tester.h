#include <iostream>
#include <cassert>
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
    int mNumberOfTestCases;
    int mCurrentScore;
    VaFunc_t mCurrentTest;

public:
    Tester() = default;
    Tester(T funcToRegister, int testCases,const char* description);
    ~Tester();
    void TestRegisteredFunc(int evaluateValue,Args... args);

    static void TestFunc(T funcToRegister,int evaluateValue, Args... args);
};

template <typename T, typename... Args>
Tester<T, Args...>::Tester(T funcToRegister, int testCases , const char* description)
    : mCurrentTest((T)funcToRegister)
    , mNumberOfTestCases(testCases)
    , mCurrentScore(0)
{
    printf("====Test : %s  START====\n",description);
}

template <typename T, typename... Args>
Tester<T,Args...>::~Tester()
{
    printf("====Test Over====\n");
}

template <typename T, typename... Args>
void Tester<T, Args...>::TestRegisteredFunc(int evaluateValue,Args... args)
{
    
    if(evaluateValue==mCurrentTest(args...))
    {
        printf("case Success, current score : %d out of  %d\n", mCurrentScore++ ,mNumberOfTestCases);
    }
    else
    {
        std::cout << "Test Fail...not sure"<<std::endl;
    }
}

//Test
template <typename T, typename... Args>
void Tester<T, Args...>::TestFunc(T funcToRegister,int evaluateValue, Args... args)
{

    if(evaluateValue==funcToRegister(args...))
    {
        std::cout << "case Success"<<std::endl;
    }
    else
    {
        std::cout << "Test Fail...not sure"<<std::endl;
    }
    
}
