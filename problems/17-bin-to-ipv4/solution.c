#include<stdio.h>
#include<string.h>
int main()
{
	char a[64];
	int bit[32];
	int octet[4];
	int i, g, bad, d, y, w;

	/* 记录：大一下原写法非法字符时 b[i] 未赋值却拿来判断；用按位 &；
	 * 通过反复 *2 把位权摊进数值，能对但对错混杂。 */
	/* 点评：不足 32 位左侧补 0；每 8 位一组按位权累加即一点分十进制。 */
	/* 优化：先校验只含 0/1；统一填 bit[0..31]；按 octet 输出或错误提示。 */

	gets_s(a, (unsigned)sizeof(a));
	g = (int)strlen(a);
	bad = 0;
	for (i = 0; i < g; i++)
	{
		if (a[i] != '0' && a[i] != '1')
		{
			bad = 1;
			break;
		}
	}
	if (g > 32)
		bad = 1;

	if (bad)
	{
		printf("该字符串不是正确的IP地址");
		return 0;
	}

	/* 高位补 0：bit[0] 为最高位 */
	for (i = 0; i < 32 - g; i++)
		bit[i] = 0;
	for (i = 0; i < g; i++)
		bit[32 - g + i] = (a[i] == '1') ? 1 : 0;

	for (d = 0; d < 4; d++)
	{
		w = 0;
		for (y = 0; y < 8; y++)
			w = w * 2 + bit[d * 8 + y];
		octet[d] = w;
	}
	printf("%d.%d.%d.%d", octet[0], octet[1], octet[2], octet[3]);
	return 0;
}
