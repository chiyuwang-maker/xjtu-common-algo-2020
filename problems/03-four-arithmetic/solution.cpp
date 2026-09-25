#include <stdio.h>
int main()
{
	int d1, d2;
	/* 记录：当时原写法 #include<math.h> 未用；缩进不齐；整数除法直接 d1/d2。 */
	/* 点评：四则入门；商为整除，除数为 0 时未定义——练习题通常保证合法输入。 */
	/* 优化：去掉无用头；整齐 IO；保留整数四则与 scanf_s。非 MSVC 可改 scanf。 */

	scanf_s("%d %d", &d1, &d2);
	printf("%d %d %d %d", d1 + d2, d1 - d2, d1 * d2, d1 / d2);
	return 0;
}
