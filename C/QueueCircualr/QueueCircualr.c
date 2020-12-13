// 개선된 원형큐
// [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ ]
#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = 0, rear = 0;
void put(int value)
{
	if ((rear + 1) % MAX == front)
	{
		puts("Queue Overflow\n"); return;
	}
	queue[rear] = value;
	rear = ++rear % MAX;
}
void show()
{
	for (int i = front; i != rear; i = ++i % MAX)
	{
		printf("%d--", queue[i]);
	}
	puts("");
}
void get()
{
	if (front == rear)
	{
		puts("Underflow"); return;
	}
	front = ++front % MAX;
}

void main()
{
	put(1);

	put(2);

	put(3);

	put(4);

	put(5);
	show();
	get();

	get();
	get();
	get();
	get();
	show();
	put(4);
	put(4);
	show();
}