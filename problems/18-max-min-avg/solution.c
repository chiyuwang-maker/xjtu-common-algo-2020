#include<stdio.h>

/* a[0] 为个数，a[1..n] 为数据；*max/*min 出参，返回平均值 */
double fun(int a[], int *max, int *min)
{
	int n, i, sum;

	/* 记录：当时原写法主函数 gets 进 char[] 再当 int* 传入；
	 * 最小值判断写成 b[p]（只用最后一个元素）；平均值除以 b[0] 而非个数。 */
	/* 点评：返回值给平均、指针出参给最值，是函数分工的好练习。 */
	/* 优化：约定 a[0]=n；正确扫 max/min/sum；平均用 n 做除数。 */

	n = a[0];
	*max = a[1];
	*min = a[1];
	sum = a[1];
	for (i = 2; i <= n; i++)
	{
		sum = sum + a[i];
		if (a[i] > *max)
			*max = a[i];
		if (a[i] < *min)
			*min = a[i];
	}
	return (double)sum / (double)n;
}

int main()
{
	int a[101];
	int n, i, max, min;
	double y;

	/* 优化：先读个数再读 n 个整数（替代 gets 乱传）。非 MSVC 可改 scanf。 */

	scanf_s("%d", &n);
	a[0] = n;
	for (i = 1; i <= n; i++)
		scanf_s("%d", &a[i]);
	y = fun(a, &max, &min);
	printf("%d %d %lf", max, min, y);
	return 0;
}
