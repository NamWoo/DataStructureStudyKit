#include <stdio.h>
#include <stdlib.h>
#include "../list.h"
#include "TEST_MACRO.h"
#include "Tester.h"
#include <crtdbg.h>

#include <malloc.h>
#include <memory.h>
#include <assert.h>
// #include "leak_detector/mem.h"


int main()
{
    
    InitTester(6,
    InitList,"리스트 초기화",1,
    AddNode,"노드추가",2,
    GetData,"i 번째 노드의 데이터 가져오기",2,
    GetListSize,"리스트 사이즈 가져오기",1,
    RemoveNodeFromList,"i 번째 노드 제거하기",2,
    DestroyList,"리스트 제거",1);
    
    // PrintResult(6);

    List* list = (List*)malloc(sizeof(List*));
    // TEST_START(리스트초기화)
    // TestAndScore(0,1,list);
    // assert(list->Head==NULL);
    // assert(list->Tail==NULL);
    

    if(_CrtDumpMemoryLeaks())
    {
        printf("memory Leaks");
    }
    else
    {
        printf("no leak");
    }
    
    return 0;
}