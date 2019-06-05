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
	Tester<VaFunc_t, List*> tester((VaFunc_t)InitList,"리스트초기화",1); //register func
	
	tester.TestRegisteredFunc(0, myList);

	free(myList);
}

