#include "TestInitialization.h"
#include "Tester.h"

#ifdef __cplusplus
extern "C"{
#include "../list.h"
}

#endif // __cplusplus



void TestInitialization()
{
	List* myList = (List*)malloc(sizeof(List));
	Tester<List*> tester((VaFunc_t)InitList,"����Ʈ�ʱ�ȭ",1); //register func
	
	tester.TestRegisteredFunc(0, myList,"�ʱ�ȭ �׽�Ʈ" );
	
	free(myList);
}

