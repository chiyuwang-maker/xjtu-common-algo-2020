#include<stdio.h>
int main()
{
	int a[200];
	int h, i, mx, cnt;

	/* 记录：当时原写法用 char a[200] 存整数；找最大时在循环里反复 b=a[i] 或 a[i+1]，
	 * 实际只保留「最后一对比较」的较大者，不是全局最大。 */
	/* 点评：先扫最大值再计数，或一遍维护 max 与 count 均可。 */
	/* 优化：改为 int 数组；一遍求最大并计数。 */

	scanf_s("%d", &h);
	if (h <= 0)
		return 0;
	scanf_s("%d", &a[0]);
	mx = a[0];
	cnt = 1;
	for (i = 1; i < h; i++)
	{
		scanf_s(" %d", &a[i]);
		if (a[i] > mx)
		{
			mx = a[i];
			cnt = 1;
		}
		else if (a[i] == mx)
			cnt++;
	}
	printf("%d,%d", mx, cnt);
	return 0;
}
