//=========================================================================================================
// stack( 연결리스트 )
//=========================================================================================================
// - head 더미노드를 이용한 단일 연결리스트 --> stack
#include<stdio.h>
#include<malloc.h>
//=========================================================================================================
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
//=========================================================================================================
Node* head;
//=========================================================================================================
void init_stack()
{
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
}
// push
// - overflow 
// - 메모리가 허용하는 한 계속해서 증가
// - top == head->next
void push(int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Out of Memory...");
		return;
	}
	newNode->data = value;
	newNode->next = head->next;
	head->next = newNode;
}
//================================================================
// pop
//  - underflow --> head->next ==NULL
//  - head-> next -->free(head->next)
//================================================================
void pop()
{
	if (head->next == NULL)
	{
		puts("Underflow");
		return;
	}
	Node* p = head->next;
	head->next = p->next;
	free(p);

}
void show()
{
	Node* p = head->next;
	while (p != NULL)
	{
		printf("[ %d ]\n", p->data);
		p = p->next;
	}
}
void main()
{
	init_stack();
	push(10);
	push(20);
	push(30);
	pop();
	pop();
	show();
}



