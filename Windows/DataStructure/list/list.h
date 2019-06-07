#pragma once

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct node
{
	struct node* Next;
	int Data;
}Node;


typedef struct list
{
	Node* Head;
	Node* Tail;
}List;

//����Ʈ�� �ʱ�ȭ�Ѵ� 
int InitList(List* list);

// int ���� data �� ����Ʈ�� Tail �ڿ� �߰��Ѵ� ������ 0 ��ȯ ���н� -1 ��ȯ�ϱ�
int AddNode(int data, List* list);

//Head ���κ��� i ��°�� ����� �����͸� �����´� ������ 0 , ���н� -1 ��ȯ�ϱ�
int GetData(int i, List* list);

// ����Ʈ�� ����� ��ȯ �ϱ�
int GetListSize(List* list);

// i ��°�� ��带 ����� (����� ���ٸ� -1, ����� �����ϸ� 0 ��ȯ)
int RemoveNodeFromList(int i, List* list);

//  ����Ʈ �����ϱ� �����Ұ� ������ -1 ��ȯ ������ 0
int DestroyList(List* list);

#ifdef __cplusplus
}
#endif // __cplusplus

