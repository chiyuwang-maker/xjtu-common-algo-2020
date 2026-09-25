#include<stdio.h>
int main()
{
	int a[3] = { 0, 0, 0 };
	int invalid = 0;
	int c;

	/* 记录：当时原写法 if (0 < c[k] < 4)——在 C 里是 (0<c[k])<4，几乎总真；
	 * 循环把哨兵 -1 也算进 invalid；未用 string.h。 */
	/* 点评：哨兵结束 + 分箱计数是选票统计的标准写法。 */
	/* 优化：读到 -1 为止；用 ==1/2/3 分箱，其余记无效。 */

	for (;;)
	{
		scanf_s("%d", &c);
		if (c == -1)
			break;
		if (c == 1)
			a[0]++;
		else if (c == 2)
			a[1]++;
		else if (c == 3)
			a[2]++;
		else
			invalid++;
	}
	printf("%d %d %d %d\n", a[0], a[1], a[2], invalid);
	return 0;
}
