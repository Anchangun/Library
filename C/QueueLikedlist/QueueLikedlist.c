// Queu ���� 
//=========================================================================================================
// Queue
//=========================================================================================================
// - head ���̳�带 �̿��� ���� ���Ḯ��Ʈ 
#include<stdio.h>
#include<malloc.h>
//=========================================================================================================
typedef struct Node
{
	int data;
	struct Node* next;
};
//=========================================================================================================
Node* head;
//=========================================================================================================
void init_Queue()
{
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
}
// push
// - overflow 
// - �޸𸮰� ����ϴ� �� ����ؼ� ����

void push(int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	Node* p = head;
	while (p->next != NULL) //���� ã�ư���.
	{
		p = p->next;
	}
	newNode->next = p->next;
	p->next = newNode;
}
//================================================================
// get
//  - underflow --> head->next ==NULL
//  - head-> next -->free(head->next)
//================================================================
void get()
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
	init_Queue();
	push(10);
	push(20);
	push(30);
	get();
	get();
	show();
}