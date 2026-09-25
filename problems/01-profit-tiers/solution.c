#include<stdio.h>
int main()
{
	int y;
	/* 记录：当时原写法层层嵌套 if-else；10 万档写成 (y-10000)*0.08+10000（疑似笔误，题面按代码保留）；
	 * 未用变量 x；printf("%d", 浮点表达式) 依赖隐式截断。 */
	/* 点评：分段提成用 else-if 链更清晰，边界落档一目了然。 */
	/* 优化：理顺为 else-if；显式 (int) 截断以贴近原输出习惯；去掉无用变量。
	 * 非 MSVC 可改 scanf。 */

	scanf_s("%d", &y);
	if (y >= 1000000)
		printf("%d", (int)((y - 1000000) * 0.01 + 42000));
	else if (y >= 600000)
		printf("%d", (int)((y - 600000) * 0.02 + 34000));
	else if (y >= 400000)
		printf("%d", (int)((y - 400000) * 0.03 + 28000));
	else if (y >= 200000)
		printf("%d", (int)((y - 200000) * 0.08 + 10000));
	else if (y >= 100000)
		printf("%d", (int)((y - 10000) * 0.08 + 10000)); /* 保留原档公式 */
	else
		printf("%d", (int)(y * 0.1));
	return 0;
}
