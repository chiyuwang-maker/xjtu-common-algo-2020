#include<stdio.h>
int main()
{
	double x, y, z;

	/* 记录：大一下原写法 if (x+y>z & x+z>y & z+y>x)——把逻辑与写成了按位 &。 */
	/* 点评：按位 & 优先级低于关系运算，此处碰巧常能「看起来对」，但不是布尔短路与，应改 &&。 */
	/* 优化：改为 &&；保留 YES / ERROR DATA 输出与 scanf_s。 */

	scanf_s("%lf %lf %lf", &x, &y, &z);
	if (x + y > z && x + z > y && z + y > x)
		printf("YES");
	else
		printf("ERROR DATA");
	return 0;
}
