#include<stdio.h>

/* 判断 n 是否回文：反转数位与原数比较 */
int ispalindrome(int n)
{
	int x, rev;

	/* 记录：当时原写法先拆位进数组，再用 | 当「不等于」；函数定义在 #include 之前；
	 * 有无意义的「result;」表达式语句。 */
	/* 点评：回文判断不必数组，反转一遍即可。 */
	x = n;
	rev = 0;
	while (x > 0)
	{
		rev = rev * 10 + x % 10;
		x = x / 10;
	}
	return rev == n;
}

int main()
{
	int n, q, a, i, b[1000];
	int first;

	/* 优化：整理头文件顺序；用反转法实现 ispalindrome；空结果不瞎打印。 */

	scanf_s("%d", &n);
	a = 0;
	for (q = 1000; q <= n; q++)
	{
		if (ispalindrome(q))
		{
			b[a] = q;
			a++;
		}
	}
	if (a == 0)
		return 0;
	first = 1;
	for (i = 0; i < a; i++)
	{
		if (!first)
			printf(" ");
		printf("%d", b[i]);
		first = 0;
	}
	return 0;
}
