//====================================================================================================================
// 1) �˻� : find
//    - 1) Node*find(int key) : key�� �ش��ϴ� ����� �����͸� ����
//    - 2) Node*search(int index) : index��°�� ����� �����͸� ����
// 2) ���� 
//    - void InsertArray(Node*Where,int*Array)
//      1���� �迭�� �Ű������� ���� �޾Ƽ� ����Ʈ�� ����
//    - void Insert(Node*Where,int cnt, int value) - Where�ڿ� value�� cnt������ŭ ����
// 3) ����
//    - void Remove(int key) : key���� ���� ��� ��带 ����
//    - void eraseRange(Node*start, Node*end) : ���� ����
//    - void Clear() : ��ü ����
// 4) ��ƿ��Ƽ
//  1) int Count() : ����Ʈ�� ����� ��ü ����
//  2) begin : 1��° ����� ������ ����
//  3) end : ������ ����� �����͸� ����
//  4) int front : ù��°�� ����� ��
//  5) int back : ������ ����� ��
//  6) toArray : ���Ḯ��Ʈ�� ���� ������ ���� �迭�� �����ϰ� �����͸� ����
//====================================================================================================================
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node* next; // ���� ���
	struct node* prev; // ���� ���
}Node;
Node* head, * tail;
Node* CreatNode(int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = newNode->prev = NULL;
	return newNode;

}
void Init()
{
	head = CreatNode(0);
	tail = CreatNode(0);
	head->next = tail;
	tail->prev = head;
}
void insert(Node* Where, int value)
{
	Node* newNode = CreatNode(value); // ��� ����
	newNode->next = Where->next;
	newNode->prev = Where;
	Where->next->prev = newNode;
	Where->next = newNode;
}
void push_front(int value) { insert(head, value); }
void push_back(int value)
{
	insert(tail->prev, value);
}
void erase(Node* Where)
{
	if (Where == head || Where == tail)
	{
		return;
	}
	Where->prev->next = Where->next;
	Where->next->prev = Where->prev;
	free(Where);
}
void pop_back()
{
	erase(tail->prev);
}
void pop_front()
{
	erase(head->next);
}

void show()
{
	for (Node* p = head->next; p != tail; p = p->next)
	{
		printf("%d-->", p->data);
	}
	puts("");
}
int Count()
{
	int cnt = 0;
	Node* p = head;
	while (p->next != tail)
	{
		p = p->next;
		cnt++;
	}
	return cnt;
}
Node* begin()
{
	Node* p;
	if (head->next != tail)
	{
		p = head->next;
		return p;
	}
}
Node* end()
{
	if (tail->prev != head)
		return tail->prev;
}
int front()
{
	Node* p;
	if (head->next != tail)
	{
		p = head->next;
		return p->data;
	}
}
int back()
{
	Node* p;
	if (tail->prev != head)
	{
		p = tail->prev;
		return p->data;
	}

}
int* toArray()
{
	int* a;
	int i = 0;
	Node* p;
	p = head;
	a = (int*)malloc(sizeof(int) * Count());
	while (p->next != tail)
	{
		p = p->next;
		a[i] = p->data;
		i++;
	}
	return a;
}
Node* find(int key)
{
	Node* p;
	p = head;
	while (p->next != tail)
	{
		if (key == p->data)
			return p;
		p = p->next;
	}
}
Node* search(int index)
{
	int cnt = 0;
	Node* p = head;
	while (p->next != tail)
	{
		if (index == cnt)
			return p;
		p = p->next;
		cnt++;
	}
}
void InsertArray(Node* Where, int* Array, int size)
{
	int i = 0;
	while (Where->next != tail)
	{
		if (size / sizeof(int) > i)
		{
			Where->data = Array[i];
			Where = Where->next;
			i++;
		}
		else
			Where = Where->next;
	}
}
void Insert(Node* Where, int cnt, int value)
{
	int i = 0;
	while (i != cnt && Where->next != tail)
	{
		Where->data = value;
		Where = Where->next;
		i++;
	}
}
void Remove(int key)
{
	Node* p = head;
	Node* s = head;
	while (p->next != tail)
	{
		if (key == p->data)
		{
			s = p->next;
			s->prev = p->prev;
			erase(p);
			p = s;
		}
		else
		{

			p = p->next;
		}
	}
	if (key == p->data)
	{
		s = p->next;
		s->prev = p->prev;
		erase(p);
	}
}
void eraseRange(Node* start, Node* end)
{
	Node* p;
	while (start->next != end->next)
	{
		p = start;
		start = start->next;
		start->prev = p->prev;
		erase(p);
	}
	p = end;
	end = end->next;
	end->prev = p->prev;
	erase(p);
}
void Clear()
{
	eraseRange(head->next, tail->prev);

}
void main()
{
	int* a;
	int b[3] = { 1,2,3 };
	int size;
	Init();
	push_back(40);
	push_back(10);
	push_back(10);
	push_back(20);
	push_back(30);
	push_front(10);
	push_back(10);
	show();
	insert(search(0), 100);
	eraseRange(find(40), find(20));
	//Remove(10);
	size = sizeof(b);
	//InsertArray(find(100), b,size);
	//Insert(find(100), 4, 5);
	Clear();
	show();
	push_back(30);
	push_back(30);
	pop_front();
	show();
	a = toArray();
	for (int i = 0; i < Count(); i++)
	{
		printf("[ %d ]", a[i]);
	}
}





