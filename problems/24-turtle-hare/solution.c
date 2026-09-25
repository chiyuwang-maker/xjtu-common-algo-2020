#include<stdio.h>
int main()
{
	int a, rabbit = 0, turtle = 0;
	int i;

	/* 记录：当时原写法变量名 b/c；未用 de/e/t；赢后打印「继续?」但未读入，直接清零续跑。 */
	/* 点评：交互小游戏——1 乌龟进一格，非 1 兔子进一格；先到 10 获胜。 */
	/* 优化：理清变量命名；去掉死变量；保留无限对局与 ASCII 示意。 */

	printf("龟兔赛跑\n玩法：随机输入一个数字，乌龟或者兔子就能前进一格\n");
	for (;;)
	{
		scanf_s("%d", &a);
		if (a == 1)
			turtle++;
		else
			rabbit++;
		printf("兔子的步数=%d\n乌龟的步数=%d\n", rabbit, turtle);
		for (i = 0; i < rabbit; i++)
			printf(" ");
		printf("*\n");
		for (i = 0; i < turtle; i++)
			printf(" ");
		printf("#\n");
		if (turtle == 10)
		{
			printf("乌龟赢了！\n继续?\n");
			rabbit = 0;
			turtle = 0;
		}
		else if (rabbit == 10)
		{
			printf("兔子赢了！\n继续?\n");
			rabbit = 0;
			turtle = 0;
		}
	}
	return 0;
}
