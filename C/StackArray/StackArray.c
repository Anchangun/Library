#include<stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;

void push(int value)
{
	if (top == MAX - 1)
	{
		puts("Stack Overflow"); return;
	}
	stack[++top] = value;
}

int pop()
{
	if (top < 0)
	{
		printf("Stack Underflow\n");
		return-1;
	}
	return stack[top--];
}
void show()
{
	for (int i = top; i >= 0; i--)
	{
		printf("[ %d ]", stack[i]);
		puts("");
	}
	puts("");
}
void main()
{
	push(10);
	push(20);
	push(30);
	show();
	pop();
	pop();
	pop();
	pop();
	show();
}
