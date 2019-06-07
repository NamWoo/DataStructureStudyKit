#include "TestDelete.h"
#include "Tester.h"


#ifdef __cplusplus
#include "../list.h"
#endif // _cplusplus



void TestDelete()
{
	List* myList = (List*)malloc(sizeof(List));
	InitList(myList);
	Tester<int, List*> tester((VaFunc_t)RemoveNodeFromList, "노드 제거하기", 7);
	tester.TestRegisteredFunc(-1, -1, myList);
	tester.TestRegisteredFunc(-1, 1, myList);
	AddNode(150, myList);
	AddNode(500, myList);
	AddNode(-100, myList);
	try
	{
		tester.TestRegisteredFunc(0, 0, myList);
		tester.TestRegisteredFunc(0, 0, myList);
		tester.TestRegisteredFunc(0, 0, myList);
		tester.TestRegisteredFunc(-1, 0, myList);
		tester.TestRegisteredFunc(-1, 40, myList);
	}
	catch (...)
	{
		std::cout << "something..." << std::endl;
	}

	DestroyList(myList);
	tester.MemoryLeakChecker();

}