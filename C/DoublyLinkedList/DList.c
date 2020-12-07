//====================================================================================================================
// 1) 검색 : find
//    - 1) Node*find(int key) : key에 해당하는 노드의 포인터를 리턴
//    - 2) Node*search(int index) : index번째의 노드의 포인터를 리턴
// 2) 삽입 
//    - void InsertArray(Node*Where,int*Array)
//      1차원 배열을 매개변수로 전달 받아서 리스트에 삽입
//    - void Insert(Node*Where,int cnt, int value) - Where뒤에 value를 cnt갯수만큼 삽입
// 3) 삭제
//    - void Remove(int key) : key값을 갖는 모든 노드를 삭제
//    - void eraseRange(Node*start, Node*end) : 구간 삭제
//    - void Clear() : 전체 삭제
// 4) 유틸리티
//  1) int Count() : 리스트의 노드의 전체 갯수
//  2) begin : 1번째 노드의 포인터 리턴
//  3) end : 마지막 노드의 포인터를 리턴
//  4) int front : 첫번째의 노드의 값
//  5) int back : 마지막 노드의 값
//  6) toArray : 연결리스트의 값을 가지고 동적 배열에 저장하고 포인터를 리턴
//====================================================================================================================
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node* next; // 다음 노드
	struct node* prev; // 이전 노드
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
	Node* newNode = CreatNode(value); // 노드 생성
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





