#include <stdio.h>

/* 欧几里得辗转相除 */
int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	int d[100], i, g, n;

	/* 记录：大一下原写法 scnaf_s 拼写错误且缺 &；枚举因子时上界用 d[1]；
	 * printf/return 写在外层 for 内导致只试 b=1 就退出；o 可能未赋值。 */
	/* 点评：以 0 为哨兵读数列后求全体 GCD，再回显——枚举因子能做，但边界易错。 */
	/* 优化：修好读入；用辗转相除累折 GCD（O(n log A)）；再打印。非 MSVC 可改 scanf。 */

	n = 0;
	scanf_s("%d", &d[0]);
	if (d[0] == 0)
	{
		return 0;
	}
	n = 1;
	for (;;)
	{
		scanf_s(" %d", &d[n]);
		if (d[n] == 0)
			break;
		n++;
	}

	g = d[0];
	for (i = 1; i < n; i++)
		g = gcd(g, d[i]);

	printf("%d\n", g);
	printf("%d", d[0]);
	for (i = 1; i < n; i++)
		printf(" %d", d[i]);
	return 0;
}
