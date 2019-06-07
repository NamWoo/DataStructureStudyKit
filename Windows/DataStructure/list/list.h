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

//리스트를 초기화한다 
int InitList(List* list);

// int 형의 data 를 리스트에 Tail 뒤에 추가한다 성공시 0 반환 실패시 -1 반환하기
int AddNode(int data, List* list);

//Head 노드로부터 i 번째의 노드의 데이터를 가져온다 성공시 0 , 실패시 -1 반환하기
int GetData(int i, List* list);

// 리스트의 사이즈를 반환 하기
int GetListSize(List* list);

// i 번째의 노드를 지운다 (지울게 없다면 -1, 지운게 성공하면 0 반환)
int RemoveNodeFromList(int i, List* list);

//  리스트 제거하기 제거할게 없으면 -1 반환 성공시 0
int DestroyList(List* list);

#ifdef __cplusplus
}
#endif // __cplusplus

