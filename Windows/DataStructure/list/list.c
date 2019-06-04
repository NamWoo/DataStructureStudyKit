#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <assert.h>

//  ����Ʈ �ʱ�ȭ�ϱ� (�ʱ�ȭ�� ����Ʈ �ޱ�, �����Ҵ� ������ ���ִ� �Լ�����ϱ�)
int InitList(List* list)
{
	list->Head = NULL;
	list->Tail = NULL;
	return 0;
}

// ��带 ����Ʈ�� �� �������� �ִ´� ���н� -1, ������ 0��ȯ
int AddNode(int data, List* list)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	list->Tail->Next = newNode;
	list->Tail = newNode;
	newNode->Next = NULL;
	return 0;
}

// ����Ʈ�� ����� ��ȯ
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

//i ��°�� ����� �����͸� �����´� ������ ����Ÿ ��ȯ, ���н� -1 ��ȯ
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

// idx ��°�� ��带 ����� (����� ���ٸ� -1, ����� �����ϸ� 0 ��ȯ)
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

//  ����Ʈ �����ϱ� �����Ұ� ������ -1 ��ȯ ������ 0
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