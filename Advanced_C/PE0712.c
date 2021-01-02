/***********************************************************/
// 1번
/***********************************************************/
#if 0

#include <stdio.h>

char * f1(int n)
{
	return "Hello" + n;
}

char * f2(int n)
{
	return "World" + n;
}

char * (*fa[2])(int) = { f1, f2 }; // [1] fa 배열 선언을 완성하라

void main(void)
{
	int f, n;

	scanf("%d %d", &f, &n);
	printf("%s\n", fa[f](n));
}

#endif

/***********************************************************/
// 2번
/***********************************************************/
#if 0

#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a*b;
}

int(*get_func(int f))(int, int)         // [1] 함수의 리턴 프로토타입을 작성
{
	switch (f)
	{
	case 0: return add;
	case 1: return sub;
	case 2: return mul;
	default: return (void *)0;
	}
}

void main(void)
{
	int f, a, b;

	scanf("%d %d %d", &f, &a, &b);
	printf("%d\n", get_func(f)(a, b));
}

#endif

/***********************************************************/
// 3번
/***********************************************************/
#if 0

#pragma warning(disable: 4214)
#pragma warning(disable: 4996)
#pragma warning(disable: 4127)
#pragma warning(disable: 4706)
#pragma pack (1)


#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int *f1(void)
{
	static int a[4] = { 1,2,3,4 };
	return a;
}

int *f2(void)
{
	static int a[4] = { 10,20,30,40 };
	return a;
}

int * (*fa[2])(void) = { f1, f2 };   // [1]

int f4(void)
{
	return 0;
}

int f5(void)
{
	return 1;
}


int * (**func1(void))(void)     // [2]
{
	return fa;
}


int *(*func2(int(*p)(void)))(void)   // [3]
{
	return func1()[p()];
}

void main(void)
{
	int n;
	int v;

	scanf("%d", &n);
	scanf("%d", &v);

	printf("%d\n", func2((n % 2) ? f4 : f5)()[v % 4]);
}

#endif

/***********************************************************/
// 4번
/***********************************************************/
#if 0

#pragma warning(disable: 4214)
#pragma warning(disable: 4996)
#pragma warning(disable: 4127)
#pragma warning(disable: 4706)
#pragma pack (1)

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct st
{
	int i;
	double f[3];
	char a[20];
};

struct st(**f1(void))    // [1]
{
	static struct st a[2] = { { 10,{ 3.14, 2.45, 1.23 }, "Enter" },{ 20,{ 6.14, 12.45, 11.23 }, "New" } };
	return &a;
}

struct st **f2(void)     // [1]
{
	static struct st a[2] = { { 30,{ 1.14, 7.45, 13.23 }, "Pointer" },{ 40,{ 16.14, 9.45, 6.23 }, "First" } };
	return &a;
}

struct st * (*fa[2])(void) = { f1, f2 };              // [2]

int f3(void)
{
	return 0;
}

int f4(void)
{
	return 1;
}

struct st *(*func1(int(*p)()))(void)   // [3]
{
	return fa[p()];
}

struct st *(*func2(int n))       // [4]
{
	if (n == 0) return func1(f3)();
	else return func1(f4)();
}

void main(void)
{
	printf("%s", (*(func2(1)[1]->a) + 2));  // [5]
	printf("%s\n", func2(0));   // [6]
}

#endif

/***********************************************************/
// 5번
/***********************************************************/
#if 01

#include <stdio.h>

char(**f2(void))[6]         //[1]
{
	static char c[4][6] = { "ENTER", "NEW", "POINT", "FIRST" };
static char(*cp[4])[6] = { c + 3, c + 2, c + 1, c };
char(**cpp)[6] = cp;

return cpp;
}

char((**f1(void))(void))[6]          //[2]
{
	return &f2;
}

void main(void)
{
	printf("%c\n", (*f1())()[0][3][3]);      //[3]
}

#endif