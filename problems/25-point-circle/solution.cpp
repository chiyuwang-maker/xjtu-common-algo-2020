#include<stdio.h>
#include<math.h>

int main()
{
	int x, y;
	double dist;

	/* 记录：大一下原写法 scanf_s("(%d,%d)", &a,&b)；随后 a=abs(a); b=abs(b);
	 * 再用 int c = sqrt((a-2)*(a-2)+(b-2)*(b-2)); 两分支均 printf("%d,%d",a,b);
	 * 已知问题：对坐标取绝对值会改点的象限；sqrt 赋给 int 会截断；
	 * 圆内/圆外两分支打印完全相同，属于未完成稿。 */

	/* 点评：圆心 (2,2)、半径 1 的位置判定，关键是「距离与半径比较」，
	 * 不必也不该先 abs；距离应用浮点保存。 */

	scanf_s("(%d,%d)", &x, &y);

	/* 优化：保留括号坐标读入；用 double 算到 (2,2) 的距离；分支输出 IN / OUT */
	dist = sqrt((double)(x - 2) * (x - 2) + (double)(y - 2) * (y - 2));
	if (dist <= 1.0)
	{
		printf("IN");
	}
	else
	{
		printf("OUT");
	}
	return 0;
}
