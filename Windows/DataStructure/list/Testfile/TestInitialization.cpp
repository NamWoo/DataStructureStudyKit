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
	Tester<List*> tester((VaFunc_t)InitList,"리스트초기화",1); //register func
	
	tester.TestRegisteredFunc(0, myList,"초기화 테스트" );
	
	free(myList);
}

