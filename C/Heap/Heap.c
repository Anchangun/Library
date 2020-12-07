//====================================================================
//  동적 메모리 ( heap) 
//  -  동적 자료 구조 
//  -  배열의 단점을 극복하는 구조... 
//====================================================================
//  배열의 종류 !! 
//====================================================================
//  1) 일반 정적 배열 :  C/C++언어 차원에서 지원해주는 배열 
//	 ex)  int arr[5]; 
//		- 장점 : 실행 속도가 빠르다.	
//		- 단점 : 크기가 고정이다. 
//				 ★ 유연하지 못하다. ( 변화에 대응할수 없다.) 
//		정적인 배열의 메모리 낭비
//		char addr[3][20] = {"",};
//		[][][][][][][][][][][][][][][]][[]][][[]
//		[][][][][][][][][][][][][][][]][[]][][[]
//		[][][][][][][][][][][][][][][]][[]][][[]
//		사용자에게 3개의 문자열 입력 받아서 저장
//	2) 동적 배열 
//		- 실행시간에 원하는 만큼의 공간을 할당하고 사용
//		- malloc : heap메모리에 공간을 할당 
//   동적 배열 단점
//    - malloc 함수는 성능 저하가 심각함
//    - 처음에 할당 이후에 재할당하는 문제가 발생함(성능)
//=============================================================================================================


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