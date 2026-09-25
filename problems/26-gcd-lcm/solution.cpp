#include <stdio.h>

int main()
{
	int m, n, g, l;

	/* 记录：大一下原写法枚举公约数，条件用按位 &；LCM=m*n/g。 */
	/* 点评：枚举能得到 GCD，但辗转相除更稳；LCM 注意先除后乘防溢出（此处保持原式）。 */
	/* 优化：& 改 &&；可选欧几里得——这里用欧几里得求 g，输出格式不变。 */

	printf("请输入两个正整数");
	scanf_s("%d %d", &m, &n);
	{
		int a = m, b = n, t;
		while (b != 0)
		{
			t = a % b;
			a = b;
			b = t;
		}
		g = a;
	}
	l = m / g * n; /* 等价 m*n/g，略减溢出机会 */
	printf("它们的最大公约数为：%d它们的最小公倍数为:%d", g, l);
	return 0;
}
