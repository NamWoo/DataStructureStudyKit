#include <stdarg.h>
#include <stdio.h>

void InitTester(int testArgCounts,...);
void PrintResult(int totalTestCounts);
void TestAndScore(int functionNum,int argc,...);

typedef int (*ArgsFuncPtr)(int argc, ...);

enum TestSize
{
    TOTAL_TESTS = 6,
    TOTAL_TEST_COUNTS=30,
};

struct Tester
{
    int (*TestFunc[TOTAL_TESTS])(int argc,...);
    char* TestDescriptions[TOTAL_TESTS];
    void(*PrintResult)(int);
    int TestResults[TOTAL_TEST_COUNTS];
    int CurrentScore;
    int argcList[TOTAL_TESTS];
}test;


