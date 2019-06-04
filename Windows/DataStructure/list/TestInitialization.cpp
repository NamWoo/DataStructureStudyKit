#include "TestInitialization.h"
#include "Tester.h"
#include "list.h"


void TestInitialization()
{
	List* myList = (List*)malloc(sizeof(List));

	Tester<VaFunc_t,List*> initTester((VaFunc_t)InitList,1,"����Ʈ �ʱ�ȭ");
	initTester.TestRegisteredFunc(0,myList);

	free(myList);
}

