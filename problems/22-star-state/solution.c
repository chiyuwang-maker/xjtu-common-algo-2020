#include<stdio.h>
#include<string.h>
int main()
{
	char a[100], b[100];
	int y, i;
	int seen_letter = 0;

	/* 记录：大一下原写法第二次 gets(b) 后用 o=strlen(b) 兼作状态，与标志位混用；
	 * 条件全是按位 &；意图接近「保留前缀星，字母照打，中段星丢弃」。 */
	/* 点评：少量标志位区分「尚未遇字母 / 已遇字母」即可。 */
	/* 优化：理顺状态——前缀 * 保留，非 * 输出，遇字母后的 * 全部丢弃；
	 * 仍读第二行以兼容原交互（内容忽略）。 */

	gets_s(a, (unsigned)sizeof(a));
	gets_s(b, (unsigned)sizeof(b));
	y = (int)strlen(a);
	for (i = 0; i < y; i++)
	{
		if (a[i] != '*')
		{
			seen_letter = 1;
			printf("%c", a[i]);
		}
		else if (!seen_letter)
		{
			printf("%c", a[i]); /* 前缀星 */
		}
		/* 已遇字母后的星号：跳过 */
	}
	return 0;
}
