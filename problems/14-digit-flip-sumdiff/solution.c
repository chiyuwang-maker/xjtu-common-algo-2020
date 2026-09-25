#include<stdio.h>

/* 将非负整数各位逆序（去前导零自然形成） */
int rev_digits(int n)
{
	int r = 0;
	if (n < 0)
		n = -n;
	do
	{
		r = r * 10 + n % 10;
		n = n / 10;
	} while (n > 0);
	return r;
}

int main()
{
	int x, y, c, d, o, u;

	/* 记录：大一下原写法拆位进数组再乘 10 重装；循环与空语句杂乱，但算法意图正确。 */
	/* 点评：由和差还原「某数」与「其逆序」再运算，是数位题常见套路。 */
	/* 优化：抽成逆序函数；逻辑不变：c=(x+y)/2, d=(x-y)/2，输出 rev(c)±rev(d)。 */

	scanf_s("%d %d", &x, &y);
	c = (x + y) / 2;
	d = (x - y) / 2;
	o = rev_digits(c);
	u = rev_digits(d);
	printf("%d %d", o + u, o - u);
	return 0;
}
