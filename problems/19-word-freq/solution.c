#include<stdio.h>
#include<string.h>

int main()
{
	char str[256];
	char words[100][32];
	int cnt[100];
	int nwords = 0;
	int i, len, j, dup, blen, w;
	char buf[32];

	/* 记录：当时原写法用空格下标切词后多层嵌套「是否与前面相同」；
	 * 标志量混乱，末尾又把下标写回 str 再整串打印，结果不可用。 */
	/* 点评：词频——切词，首次登记、重复累加即可。 */
	/* 优化：遇 '#' 结束；空格分词；查表计数；输出 词-次数。
	 * MSVC 用 gets_s / strcpy_s；非 MSVC 可改 fgets + strcpy。 */

	gets_s(str, (unsigned)sizeof(str));
	len = (int)strlen(str);
	blen = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i] == '#')
			break;
		if (str[i] != ' ')
		{
			if (blen < (int)sizeof(buf) - 1)
				buf[blen++] = str[i];
			continue;
		}
		if (blen == 0)
			continue;
		buf[blen] = '\0';
		dup = -1;
		for (j = 0; j < nwords; j++)
		{
			if (strcmp(words[j], buf) == 0)
			{
				dup = j;
				break;
			}
		}
		if (dup >= 0)
			cnt[dup]++;
		else if (nwords < 100)
		{
			strcpy_s(words[nwords], (unsigned)sizeof(words[0]), buf);
			cnt[nwords] = 1;
			nwords++;
		}
		blen = 0;
	}
	/* 末词（# 前无空格时） */
	if (blen > 0)
	{
		buf[blen] = '\0';
		dup = -1;
		for (j = 0; j < nwords; j++)
		{
			if (strcmp(words[j], buf) == 0)
			{
				dup = j;
				break;
			}
		}
		if (dup >= 0)
			cnt[dup]++;
		else if (nwords < 100)
		{
			strcpy_s(words[nwords], (unsigned)sizeof(words[0]), buf);
			cnt[nwords] = 1;
			nwords++;
		}
	}

	for (w = 0; w < nwords; w++)
	{
		if (w)
			printf(" ");
		printf("%s-%d", words[w], cnt[w]);
	}
	return 0;
}
