#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <assert.h>

//  리스트 초기화하기 (초기화할 리스트 받기, 동적할당 해제를 해주는 함수등록하기)
int InitList(List* list)
{
	list->Head = NULL;
	list->Tail = NULL;
	return 0;
}

// 노드를 리스트의 맨 마지막에 넣는다 실패시 -1, 성공시 0반환
int AddNode(int data, List* list)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	list->Tail->Next = newNode;
	list->Tail = newNode;
	newNode->Next = NULL;
	return 0;
}

// 리스트의 사이즈를 반환
int GetListSize(List* list)
{
	int size = 0;
	Node* searchNode = list->Head;
	while (searchNode)
	{
		searchNode = searchNode->Next;
		size++;
	}
	return size;
}

//i 번째의 노드의 데이터를 가져온다 성공시 데이타 반환, 실패시 -1 반환
int GetData(int i, List* list)
{
	int temp = 0;
	Node* searchNode = list->Head;
	if (searchNode == NULL)return -1;
	while (temp++ != i)
	{
		searchNode = searchNode->Next;
	}
	return searchNode->Data;
}

// idx 번째의 노드를 지운다 (지울게 없다면 -1, 지운게 성공하면 0 반환)
int RemoveNodeFromList(int idx, List* list)
{
	int temp = 0;
	Node* searchNode = list->Head;
	if (searchNode == NULL) return -1;
	while (idx != temp++)
	{
		searchNode = searchNode->Next;
	}
	free(searchNode);
	return 0;
}

//  리스트 제거하기 제거할게 없으면 -1 반환 성공시 0
int DestroyList(List* list)
{
	if (list->Head == NULL)return -1;
	while (list->Head)
	{
		Node* temp = list->Head;
		list->Head = list->Head->Next;
		free(temp);
	}
	return 0;
}