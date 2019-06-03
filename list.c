#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <assert.h>
#include "TEST_MACRO.h"

//  리스트 초기화하기 (초기화할 리스트 받기, 동적할당 해제를 해주는 함수등록하기)
int InitList(List* list)
{
    printf("리스트 초기화중...");
    list->Head = NULL;
    list->Tail = NULL;
}



// 노드를 리스트의 맨 마지막에 넣는다 실패시 -1, 성공시 0반환
int AddNode(int data, List* list)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = data;
    list->Tail->Next = newNode;
    list->Tail = newNode;
}

// 리스트의 사이즈를 반환
int GetListSize(List* list)
{

}

//i 번째의 노드의 데이터를 가져온다
int GetData(int i,List* list)
{

}

// idx 번째의 노드를 지운다 (지울게 없다면 -1, 지운게 성공하면 0 반환)
int RemoveNodeFromList(int idx, List* list)
{

}

void TestList()
{

}
//  리스트 제거하기 제거할게 없으면 -1 반환 성공시 0
int DestroyList(List* list)
{
    printf("노드 제거중...\n");
    Node* temp = list->Head;
    
    while (temp)  
    {
        free(temp);
        temp = temp->Next;
    }

    free(list);
    return 0;
}