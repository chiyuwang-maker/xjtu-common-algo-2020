#include<stdio.h>
#include<string.h>
int main()
{
	char d[1000];
	int a, i;

	/* 记录：大一下原写法先找首尾非星再过滤中段；gets；右端 e>0 漏下标 0。 */
	/* 点评：本题要删光所有 '*'，直接跳过星号输出即可（与 16 题「只剥边」不同）。 */
	/* 优化：gets_s + 单遍过滤。非 MSVC 可改 fgets。 */

	gets_s(d, (unsigned)sizeof(d));
	a = (int)strlen(d);
	for (i = 0; i < a; i++)
	{
		if (d[i] != '*')
			printf("%c", d[i]);
	}
	return 0;
}
