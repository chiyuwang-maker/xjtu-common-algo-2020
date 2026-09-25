#include <stdio.h>
int main()
{
	char ab;
	/* 记录：当时原写法 if (ab = 'A') / if (ab = 'Z')——把比较写成了赋值 */
	/* 点评：赋值表达式在 if 里几乎总为真，A/Z 环形分支实际走偏；
	 * 中间字母用 >'A' && <'Z' 本身能覆盖 B..Y，边界应单独用 == 处理。 */
	/* 优化：改为 ==，并用 else if 理顺；scanf_s 读字符贴近 VS 风格。
	 * 非 MSVC 下 %c 可改 scanf(" %c", &ab)；MSVC 的 scanf_s("%c") 有时需缓冲区大小参数。 */

	scanf_s(" %c", &ab);
	if (ab > 'A' && ab < 'Z')
		printf("%c%c%c", ab - 1, ab, ab + 1);
	else if (ab == 'A')
		printf("%c%c%c", 'Z', ab, ab + 1);
	else if (ab == 'Z')
		printf("%c%c%c", ab - 1, ab, 'A');
	return 0;
}
