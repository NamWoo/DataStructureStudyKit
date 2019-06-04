#include "TestInitialization.h"
#include "Tester.h"
#include "../list.h"


void TestInitialization()
{
    List* myList = (List*)malloc(sizeof(List));

    Tester<VaFunc_t,List*> initTester((VaFunc_t)InitList,1,"리스트 초기화");
    initTester.TestRegisteredFunc(0,myList);
    
    free(myList);
}

