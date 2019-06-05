#include "TestInsertion.h"
#include "Tester.h"
#include <crtdbg.h>



#ifdef __cplusplus
#include "../list.h"
#endif // __cplusplus

void TestInsertion()
{
	
	List* list = new List();

	Tester<VaFunc_t, int, List*> tester((VaFunc_t)AddNode, "노드 삽입 테스트...",5);
	tester.TestRegisteredFunc(0, 0, list);
	tester.TestRegisteredFunc(0, 1, list);
	tester.TestRegisteredFunc(0, 2, list);
	tester.TestRegisteredFunc(0, 3, list);
	tester.TestRegisteredFunc(0, 4, list);
	tester.TestRegisteredFunc(0, 5, list);
	DestroyList(list);
	_CrtDumpMemoryLeaks();
	
}