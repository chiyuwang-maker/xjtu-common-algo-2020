#include<stdio.h>
int main()
{
	double h = 100.0;
	double path = 0.0;
	double bounce;
	int i;

	/* 记录：大一下原写法 for 10 次：path+=h; h*=0.5——只累加了每次「下落段」，
	 * 未计入第 2..10 次落地前的「上升段」，与经典「路程」题意不完全一致。 */
	/* 点评：第 1 次落地路程 100；之后每次落地贡献「上升+下落」各为上一反弹高；
	 * 第 10 次反弹高 = 100/2^10。 */
	/* 优化：按经典题意补上上升段；用 double 与 %.6f 输出。 */

	path = h;           /* 第 1 次落下 */
	for (i = 1; i < 10; i++)
	{
		h = h * 0.5;    /* 第 i 次反弹高度 */
		path = path + h + h; /* 升 + 再落 */
	}
	bounce = h * 0.5;   /* 第 10 次反弹 */
	printf("第十次落地时共经过%.6f\n第十次反弹%.6f米", path, bounce);
	return 0;
}
