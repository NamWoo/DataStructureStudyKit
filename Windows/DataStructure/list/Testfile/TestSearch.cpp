#include "Tester.h"
#include "TestSearch.h"

#ifdef __cplusplus
extern "C"
{
#include "../list.h"
}
#endif 


void TestSearch()
{
	List* myList = (List*)malloc(sizeof(List));
	InitList(myList);
	Tester<int, List*> tester((VaFunc_t)GetData, "데이타 가져오기", 7);
	tester.TestRegisteredFunc(-1, 3, myList,"아무것도 없을때");
	tester.TestRegisteredFunc(-1, 5, myList,"아무것도 없을때");
	AddNode(400, myList);
	AddNode(100, myList);
	AddNode(50, myList);
	AddNode(60, myList);
	AddNode(70, myList);
	tester.TestRegisteredFunc(400, 0, myList);
	tester.TestRegisteredFunc(100, 1, myList);
	tester.TestRegisteredFunc(50, 2, myList);
	tester.TestRegisteredFunc(60, 3, myList);
	tester.TestRegisteredFunc(70, 4, myList);
	DestroyList(myList);
	tester.MemoryLeakChecker();
}