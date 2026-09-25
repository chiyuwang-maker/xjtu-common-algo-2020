#include<stdio.h>
int main()
{
	int a, k, start, end, c;

	/* 记录：大一下原写法按段长 i 奇偶分支拼首末项；条件用按位 &；
	 * for (c=...; ...; c=c++) 既怪又依赖旧值；偶数段循环上界有 -3 等魔法数，易漏项/多项。 */
	/* 点评：连续 k 项之和为 a ⇔ 2a 可被 k 整除且首项 start=(2a/k-k+1)/2 为正整数。 */
	/* 优化：统一用 start 公式构造区间并打印；k 从大到小以贴近原输出顺序倾向。 */

	scanf_s("%d", &a);
	for (k = a; k >= 2; k--)
	{
		if ((2 * a) % k != 0)
			continue;
		/* start = (2a/k - k + 1) / 2，且必须整除（已由 2a%k==0 与奇偶匹配保证） */
		if ((2 * a / k - k + 1) % 2 != 0)
			continue;
		start = (2 * a / k - k + 1) / 2;
		if (start <= 0)
			continue;
		end = start + k - 1;
		printf("%d=%d", a, start);
		for (c = start + 1; c <= end; c++)
			printf("+%d", c);
		printf("\n");
	}
	return 0;
}
