#include <stdio.h>
int main()
{
	char ab[4];
	int u;

	/* 记录：当时原写法 void main；连续 scanf_s("%c") 读 4 字符。
	 * Project4 为更乱草稿，已另附。 */
	/* 点评：体会 char 既是字符又是小整数；+1 得到后继码点（未必可打印）。 */
	/* 优化：改为 int main；保留逐字符读入与三列输出。
	 * MSVC 的 scanf_s("%c") 有时需缓冲区大小：scanf_s("%c", &ab[u], 1)；
	 * 非 MSVC 可改 scanf("%c", &ab[u])。 */

	for (u = 0; u < 4; u++)
	{
		scanf_s("%c", &ab[u], 1);
		printf("%c %d %c\n", ab[u], (int)ab[u], ab[u] + 1);
	}
	return 0;
}
