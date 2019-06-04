#include "Tester.h"


void InitTester(int testArgCounts,...)
{
    tester.CurrentScore = 0;    
    tester.PrintResult = PrintResult;
    va_list testListStartPointer;
    va_start(testListStartPointer,testArgCounts);
    int i;
    for(i=0; i<testArgCounts;++i)
    {
        tester.TestFunc[i] = (ArgsFuncPtr)va_arg(testListStartPointer,int*);
        tester.TestDescriptions[i] = (char*)va_arg(testListStartPointer,char*);
        tester.argcList[i] = (int)va_arg(testListStartPointer,int);
    }
    va_end(testListStartPointer);
}


void PrintResult(int totalTestCounts)
{
    
    int i;
    for(i=0; i<totalTestCounts; ++i)
    {
        printf("Test 구조체 내의 각 함수 명세 : %s\n",tester.TestDescriptions[i]);
        printf("Test 구조체 내의 각 함수 출력값 : %d\n",tester.TestResults[i]);
        printf("Test 구조체 내의 각 함수 매개변수값 : %d\n",tester.argcList[i]);
        
    }
}


void TestAndScore(int functionNum,int argc,...)
{
    int i;
    va_list argList;
    va_start(argList,argc);
    tester.TestFunc[i](va_arg(argList,void*));
    va_end(argList);
}