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
	Tester<int, List*> tester((VaFunc_t)AddNode, "³ëµå »ğÀÔ Å×½ºÆ®...",6);
	tester.TestRegisteredFunc(0, 0, list,"³ëµå»ğÀÔ0 ");
	tester.TestRegisteredFunc(0, 1, list,"³ëµå»ğÀÔ0 ");
	tester.TestRegisteredFunc(0, 2, list,"³ëµå»ğÀÔ0 ");
	tester.TestRegisteredFunc(0, 3, list,"³ëµå»ğÀÔ0 ");
	tester.TestRegisteredFunc(0, 4, list,"³ëµå»ğÀÔ0 ");
	tester.TestRegisteredFunc(0, 5, list,"³ëµå»ğÀÔ0 ");

	DestroyList(list);
	tester.MemoryLeakChecker();
	
}