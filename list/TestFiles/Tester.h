#include <stdarg.h>
#include <stdio.h>

typedef int (*ArgsFuncPtr)(int argc, ...);

void InitTester(int testArgCounts,...);
void PrintResult(int totalTestCounts);
void TestAndScore(int functionNum,int argc,...);

//TODO
// 구현해야함 
void PrintResult();

//ERROR_CODE 발생, SUCCESS_CODE 발생, 해당 함수에 해당되는 인자수 입력, 인자입력
int TestDataStructureFunction(ArgsFuncPtr functionForTest , int argc,...); 

//ERROR_CODE 에 따른 성적 
void TestScoring(); 

//각 테스트 모듈을 실행한다 
//(initialize module, insertion module, delete module, search module, destroy module)
void  TestModuleStarter(ArgsFuncPtr);


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
}tester;


