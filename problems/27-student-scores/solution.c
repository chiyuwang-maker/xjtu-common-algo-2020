#include<stdio.h>
#include<string.h>

/*
 * 记录：当时原草稿里还写过一个无关的 struct Platfom / Jackson，
 * 以及 Jackson.character[8] = {'a',...} 这类非法「数组整体赋值」；
 * 录入循环里 gets + 残缺的 scanf_s; 且用 %d 去读 float score；
 * 最后 printf 未初始化的 float a。整份是结构体练习未完成稿。
 */

struct Student
{
	int num;
	char name[20];
	float score[3];
} student[10];

int main()
{
	int i, u;
	float sum, avg;

	/* 点评：结构体数组入门——每人学号、姓名、三门成绩；再算平均即可闭环。 */

	printf("请开始录入成绩\n");
	for (i = 0; i < 10; i++)
	{
		printf("请录入第%d个同学的学号、姓名、三门成绩：", i + 1);
		/* 优化：补全读入；姓名用 %s（MSVC 下 scanf_s 需带缓冲区大小）。
		 * 非 MSVC 可改：scanf("%d %s %f %f %f", ...) */
		scanf_s("%d", &student[i].num);
		scanf_s("%s", student[i].name, (unsigned)sizeof(student[i].name));
		for (u = 0; u < 3; u++)
		{
			scanf_s("%f", &student[i].score[u]);
		}
	}

	printf("学号 姓名 平均分\n");
	for (i = 0; i < 10; i++)
	{
		sum = 0;
		for (u = 0; u < 3; u++)
		{
			sum = sum + student[i].score[u];
		}
		avg = sum / 3;
		printf("%d %s %.2f\n", student[i].num, student[i].name, avg);
	}
	return 0;
}
