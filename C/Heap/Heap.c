#include <stdio.h> 
#include <malloc.h> 
#include <string.h>

void Init(char*** addr) // �ʱ� ���� 
{
	int size = 0;
	printf("���� ������ ?? ");
	scanf("%d", &size);
	getchar();

	*addr = (char**)calloc(size, sizeof(char*));

}

void insert(char** addr)
{
	char buf[256];
	gets(buf);
	for (int i = 0; i < _msize(addr) / sizeof(char*); i++)
	{
		if (addr[i] == NULL)
		{
			addr[i] = (char*)malloc(sizeof(char) * strlen(buf) + 1);
			strcpy(addr[i], buf);
			return;
		}
	}
	puts("����");
}
void show(char** addr)
{

	for (int i = 0; i < _msize(addr) / sizeof(char*); i++)
	{
		if (addr[i] != NULL)
			printf("[ %d ] -> %s \n", i, addr[i]);
		else
			printf("[ %d ] -> NULL \n", i);
	}

}


void main()
{
	char** addr = NULL;
	// addr = Init(); // ���� �޴´� !! 
	Init(&addr);
	insert(addr);
	show(addr);
	insert(addr);
	show(addr);
	insert(addr);
	show(addr);
	insert(addr);
	show(addr);
}