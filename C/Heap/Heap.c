//====================================================================
//  ���� �޸� ( heap) 
//  -  ���� �ڷ� ���� 
//  -  �迭�� ������ �غ��ϴ� ����... 
//====================================================================
//  �迭�� ���� !! 
//====================================================================
//  1) �Ϲ� ���� �迭 :  C/C++��� �������� �������ִ� �迭 
//	 ex)  int arr[5]; 
//		- ���� : ���� �ӵ��� ������.	
//		- ���� : ũ�Ⱑ �����̴�. 
//				 �� �������� ���ϴ�. ( ��ȭ�� �����Ҽ� ����.) 
//		������ �迭�� �޸� ����
//		char addr[3][20] = {"",};
//		[][][][][][][][][][][][][][][]][[]][][[]
//		[][][][][][][][][][][][][][][]][[]][][[]
//		[][][][][][][][][][][][][][][]][[]][][[]
//		����ڿ��� 3���� ���ڿ� �Է� �޾Ƽ� ����
//	2) ���� �迭 
//		- ����ð��� ���ϴ� ��ŭ�� ������ �Ҵ��ϰ� ���
//		- malloc : heap�޸𸮿� ������ �Ҵ� 
//   ���� �迭 ����
//    - malloc �Լ��� ���� ���ϰ� �ɰ���
//    - ó���� �Ҵ� ���Ŀ� ���Ҵ��ϴ� ������ �߻���(����)
//=============================================================================================================


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