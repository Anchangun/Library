//===================================================================================================================
// Queue의 구현 --> 배열
#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = 0, rear = 0;
void put(int value)
{
	if (rear >= MAX)
	{
		printf("Queue Overflow\n"); return;
	}
	queue[rear] = value;
	rear++;
}
void get()
{
	if (front == rear)
	{
		printf("Queue Underflow\n"); return;
	}
	front++;
}
void show()
{
	for (int i = front; i < rear; i++)
	{
		printf("[ %d ]\n", queue[i]);
	}
	puts("");

}
void main()
{
	put(10);
	show();
	put(20);
	show();
	put(30);
	show();
	put(40);
	show();
	put(50);
	show();
	put(60);
	show();
	get();
	show();
	get();
	show();
	get();
	show();
	get();
	show();
	get();
	show();
	get();
	show();
}