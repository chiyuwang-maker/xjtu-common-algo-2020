#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int len, left, right, i;

	/* 记录：当时原写法 gets（已弃用/不安全）；从右找非星时 p>0 漏掉下标 0；
	 * 未用的 c[]/j 等变量。 */
	/* 点评：左右夹逼找首尾非 '*'，再输出闭区间子串即可。 */
	/* 优化：MSVC 用 gets_s；修正右端扫描；全星时输出空。
	 * 非 MSVC 可改 fgets(a, sizeof a, stdin) 并去掉行末换行。 */

	gets_s(a, (unsigned)sizeof(a));
	len = (int)strlen(a);
	left = 0;
	while (left < len && a[left] == '*')
		left++;
	right = len - 1;
	while (right >= left && a[right] == '*')
		right--;
	for (i = left; i <= right; i++)
		printf("%c", a[i]);
	return 0;
}
