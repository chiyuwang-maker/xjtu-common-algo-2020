#include<stdio.h>

int main()
{
	int a[10000];
	int x, y, m, n, t, i, q, z;
	int first;

	/* 记录：大一下原写法用 pow(10,n) 得 double t，再 (int)t 取模；int t 与 double t 同名阴影；
	 * 若区间内无自守数，打印 a[-1]。 */
	/* 点评：自守数判定「m² 末 n 位 == m」即 (m*m-m) % 10^n == 0；位数用整除计数即可。 */
	/* 优化：改整数累乘求 10^n，避免 pow；无结果时不输出；保留扫描+收集。 */

	scanf_s("%d %d", &x, &y);
	i = 0;
	for (m = x; m <= y; m++)
	{
		z = m;
		n = 0;
		do
		{
			z = z / 10;
			n++;
		} while (z > 0);

		t = 1;
		for (q = 0; q < n; q++)
			t = t * 10;

		if ((m * m - m) % t == 0)
		{
			a[i] = m;
			i++;
		}
	}

	if (i == 0)
		return 0;

	first = 1;
	for (q = 0; q < i; q++)
	{
		if (!first)
			printf(" ");
		printf("%d", a[q]);
		first = 0;
	}
	return 0;
}
