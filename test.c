#include "test.h"


void InitTester(int testArgCounts,...)
{
    test.CurrentScore = 0;    
    test.PrintResult = PrintResult;
    va_list testListStartPointer;
    va_start(testListStartPointer,testArgCounts);
    int i;
    for(i=0; i<testArgCounts;++i)
    {
        test.TestFunc[i] = (ArgsFuncPtr)va_arg(testListStartPointer,int*);
        test.TestDescriptions[i] = (char*)va_arg(testListStartPointer,char*);
        test.argcList[i] = (int)va_arg(testListStartPointer,int);
    }
    va_end(testListStartPointer);
}


void PrintResult(int totalTestCounts)
{
    
    int i;
    for(i=0; i<totalTestCounts; ++i)
    {
        printf("Test 구조체 내의 각 함수 명세 : %s\n",test.TestDescriptions[i]);
        printf("Test 구조체 내의 각 함수 출력값 : %d\n",test.TestResults[i]);
        printf("Test 구조체 내의 각 함수 매개변수값 : %d\n",test.argcList[i]);
        
    }
}


void TestAndScore(int functionNum,int argc,...)
{
    int i;
    va_list argList;
    va_start(argList,argc);
    test.TestFunc[i](va_arg(argList,void*));
    va_end(argList);
}