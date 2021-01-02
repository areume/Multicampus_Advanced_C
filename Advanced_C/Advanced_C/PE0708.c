/***********************************************************/
// 7월 8일 과정평가 1번
/***********************************************************/

#if 0
#include <stdio.h>

char Change_Case(char a)
{
	if (a >= 'A' && a <= 'Z')
		return a + 32;
	else
		return a - 32;
}

int main(void)
{
	char a;
	scanf("%c", &a);
	printf("%c\n", Change_Case(a));

	return 0;
}
#endif

/***********************************************************/
// 7월 8일 과정평가 2번
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i, part = 1, total = 0;

	int N;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		part *= i;
		total += part;
	}
	printf("%d\n", total);

	return 0;
}

#endif

/***********************************************************/
// 7월 8일 과정평가 3번
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i, max, maxi;
	int a[9];

	for (i = 0; i<9; i++)
	{
		scanf("%d", &a[i]);
	}

	max = a[0]; maxi = 0;
	for (i = 1; i<9; i++)
	{
		if (max<a[i])
		{
			max = a[i];
			maxi = i;
		}
	}

	printf("%d\n%d\n", max, maxi + 1);

	return 0;
}
#endif

/***********************************************************/
// 7월 8일 과정평가 4번
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i, j, max;
	int people[4][2];
	int train[4] = { 0 };

	for (i = 0; i<4; i++)
	{
		for (j = 0; j<2; j++)
		{
			scanf("%d", &people[i][j]);
		}
	}

	train[0] = train[0] - people[0][0] + people[0][1];

	for (i = 1; i<4; i++)
	{
		train[i] = train[i - 1] - people[i][0] + people[i][1];
	}

	max = train[0];
	for (i = 1; i<4; i++)
	{
		if (max<train[i])
			max = train[i];
	}

	printf("%d\n", max);

	return 0;
}

#endif

/***********************************************************/
// 7월 8일 과정평가 5번
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i, j;
	char word[100][100];
	char ch = 'A';

	int n;
	scanf("%d", &n);

	for (i = n - 1; i >= 0; i--)
	{
		for (j = n - 1; j >= 0; j--)
		{
			word[j][i] = ch++;

			if (ch>'Z')
				ch = 'A';
		}
	}

	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			printf("%c ", word[i][j]);
		}
		printf("\n");
	}
	return 0;
}

#endif