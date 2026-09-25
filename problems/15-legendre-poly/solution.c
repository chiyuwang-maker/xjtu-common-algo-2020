#include<stdio.h>

/* 迭代求勒让德 Pn(x)；P0=1, P1=x, Pn=((2n-1)x Pn-1-(n-1)Pn-2)/n */
double poly(int n, double x)
{
	double p0, p1, p;
	int k;

	/* 记录：当时原写法 long float（非标准）；裸递归导致指数级重复计算；
	 * 函数定义在 #include 之前；%lf 读入 long float 也不匹配。 */
	/* 点评：递推式天然适合自底向上迭代，O(n) 且无栈风险。 */
	/* 优化：改 double + 迭代；保留同一递推公式。 */

	if (n == 0)
		return 1.0;
	if (n == 1)
		return x;
	p0 = 1.0;
	p1 = x;
	p = p1;
	for (k = 2; k <= n; k++)
	{
		p = ((2 * k - 1) * x * p1 - (k - 1) * p0) / k;
		p0 = p1;
		p1 = p;
	}
	return p;
}

int main()
{
	int a;
	double c;

	scanf_s("%d %lf", &a, &c);
	printf("%lf\n", poly(a, c));
	return 0;
}
