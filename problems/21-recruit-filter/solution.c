#include<stdio.h>
int main()
{
	int a, u, h, q, y, t, f;
	int ab[6001], cd[6001];

	/* 记录：大一下原写法条件 a>3 & a<6000 用按位 &；a==3 特判；交替删偶数位/3 倍数位。 */
	/* 点评：约瑟夫变体——按「当前队列下标」淘汰，两轮规则轮换直到剩余≤3。 */
	/* 优化：& 改 &&；逻辑保持；提示语与输出格式不变。 */

	printf("输入你想要的新兵数字是：");
	scanf_s("%d", &a);
	if (a == 3)
	{
		printf("%d %d %d", 1, 2, 3);
		return 0;
	}
	if (a > 3 && a < 6000)
	{
		for (q = 0; q < a; q++)
			ab[q] = q + 1;
		u = a;
		for (;;)
		{
			h = 0;
			for (q = 0; q < u; q++)
			{
				if ((q + 1) % 2 != 0)
				{
					cd[h] = ab[q];
					h++;
				}
			}
			u = h;
			if (u <= 3)
			{
				printf("%d", cd[0]);
				for (t = 1; t < u; t++)
					printf(" %d", cd[t]);
				break;
			}
			h = 0;
			for (y = 0; y < u; y++)
			{
				if ((y + 1) % 3 != 0)
				{
					ab[h] = cd[y];
					h++;
				}
			}
			u = h;
			if (u <= 3)
			{
				printf("%d", ab[0]);
				for (f = 1; f < u; f++)
					printf(" %d", ab[f]);
				break;
			}
		}
	}
	return 0;
}
