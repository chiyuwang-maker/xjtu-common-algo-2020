#include<stdio.h>

/* 把 a[left..right] 原地逆置；交换只用一个 int 临时量 */
void reverse(int a[], int left, int right)
{
	int t;
	while (left < right)
	{
		t = a[left];
		a[left] = a[right];
		a[right] = t;
		left++;
		right--;
	}
}

int main()
{
	int a, l;
	/* 记录：当时原写法带扫尾换行 scanf_s("%d %d\n", ...)；非 MSVC 可改 scanf */
	scanf_s("%d %d", &a, &l);
	int c[200];
	scanf_s("%d", &c[0]);
	for (int i = 1; i < a; i++)
	{
		scanf_s(" %d", &c[i]);
	}

	int b = l % a; /* 实际右移位数；b==0 时序列不变 */

	/*
	 * 记录：当时原写法按 a 与步长整除关系分支——
	 *   1) a%b==0 时反复「整体右挪一格」（临时量 p 接住末元再塞到头）；
	 *   2) a%(a-b)==0 时反复「整体左挪一格」；
	 *   3) 否则沿环做置换：q=(p+b)%a，用 e/i 两个整型倒手被覆盖的值。
	 * 已知问题：挪格循环用了 <= 导致次数偏多；两分支可能同时成立而串着跑；
	 * 右挪时 h 扫到 0 会读 c[-1]；条件里用了按位 & 而非 &&。
	 * 原挪格/环置换思路仅作史料保留，主路径不再走。
	 */

	/* 点评：分支挪格/环置换能做对一部分样例，但边界与次数难控，也难一次讲清。 */

	/*
	 * 优化：改为三次逆置（截点倒位）完成右移 b 位——
	 *   reverse(0, a-b-1);  reverse(a-b, a-1);  reverse(0, a-1);
	 * 等价说法：先整段倒转，再倒转前 b，再倒转后 a-b（顺序可变，截点一致即可）。
	 * 时间 O(a)，额外空间仅逆置里那一个 int。
	 * （口语有时叫「快排方法」，指的是这种又快又省的原地套路，不是 quicksort。）
	 */
	if (b != 0)
	{
		reverse(c, 0, a - b - 1);
		reverse(c, a - b, a - 1);
		reverse(c, 0, a - 1);
	}

	printf("%d", c[0]);
	for (int i = 1; i < a; i++)
	{
		printf(" %d", c[i]);
	}
	return 0;
}
