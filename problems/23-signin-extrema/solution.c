#include<stdio.h>
#include<string.h>
int main()
{
	struct dagongren
	{
		char ID_number[20];
		char Sign_in_time[9];
		char Sign_out_time[9];
	} worker[101];
	int n, i;
	char first[9], last[9], first_ID[20], last_ID[20];

	/* 记录：当时原写法 scanf_s("%s %s %s", ..., &Sign_in_time, ...)——对数组多取了 &；
	 * MSVC 的 scanf_s 读字符串还应传缓冲区大小。 */
	/* 点评：HH:MM:SS 字典序即时间序，strcmp 可直接比早晚。 */
	/* 优化：补上缓冲区大小；去掉错误的 &；逻辑保持最早签到 / 最晚签退。 */

	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%s %s %s",
			worker[i].ID_number, (unsigned)sizeof(worker[i].ID_number),
			worker[i].Sign_in_time, (unsigned)sizeof(worker[i].Sign_in_time),
			worker[i].Sign_out_time, (unsigned)sizeof(worker[i].Sign_out_time));
	}
	strcpy_s(first, (unsigned)sizeof(first), worker[0].Sign_in_time);
	strcpy_s(last, (unsigned)sizeof(last), worker[0].Sign_out_time);
	strcpy_s(first_ID, (unsigned)sizeof(first_ID), worker[0].ID_number);
	strcpy_s(last_ID, (unsigned)sizeof(last_ID), worker[0].ID_number);
	for (i = 1; i < n; i++)
	{
		if (strcmp(worker[i].Sign_in_time, first) < 0)
		{
			strcpy_s(first, (unsigned)sizeof(first), worker[i].Sign_in_time);
			strcpy_s(first_ID, (unsigned)sizeof(first_ID), worker[i].ID_number);
		}
		if (strcmp(worker[i].Sign_out_time, last) > 0)
		{
			strcpy_s(last, (unsigned)sizeof(last), worker[i].Sign_out_time);
			strcpy_s(last_ID, (unsigned)sizeof(last_ID), worker[i].ID_number);
		}
	}
	printf("%s %s", first_ID, last_ID);
	return 0;
}
