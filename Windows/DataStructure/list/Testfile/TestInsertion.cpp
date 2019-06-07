#include "TestInsertion.h"
#include "Tester.h"
#include <crtdbg.h>



#ifdef __cplusplus
#include "../list.h"
#endif // __cplusplus

void TestInsertion()
{
	
	List* list = new List();
	Node* checker;
	Tester<int, List*> tester((VaFunc_t)AddNode, "��� ���� �׽�Ʈ...",6);
	tester.TestRegisteredFunc(0, 0, list,"������0 ");
	tester.TestRegisteredFunc(0, 1, list,"������0 ");
	tester.TestRegisteredFunc(0, 2, list,"������0 ");
	tester.TestRegisteredFunc(0, 3, list,"������0 ");
	tester.TestRegisteredFunc(0, 4, list,"������0 ");
	tester.TestRegisteredFunc(0, 5, list,"������0 ");

	DestroyList(list);
	tester.MemoryLeakChecker();
	
}