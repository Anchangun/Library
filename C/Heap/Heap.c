#include <stdio.h> 
#include <malloc.h> 
#include <string.h>

void Init(char*** addr) // 초기 설정 
{
	int size = 0;
	printf("저장 사이즈 ?? ");
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
	puts("꽉참");
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
	// addr = Init(); // 리턴 받는다 !! 
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