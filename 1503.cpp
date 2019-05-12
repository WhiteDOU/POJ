#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
#define MAX 105

char sum[MAX][MAX];
string str;

int main()
{
	int i, j, he, jin, line;

	for (i = 0;; i++)
	{
		cin >> str;
		if (str == "0") break;
		/* 0号元素记录长度 */
		sum[i][0] = str.size();
		/* 逆序存放大整数 */
		for (j = 1; j <= sum[i][0]; j++)
		{
			sum[i][j] = str[sum[i][0] - j] - '0';
		}
	}

	/* 记录数据行数 */
	line = i;

	/* 用第0行存放和 */
	for (i = 1; i < line; i++)
	{
		/* 进位标记归0 */
		jin = 0;
		/* 进行加法运算 */
		for (j = 1; j < MAX - 1; j++)
		{
			he = sum[0][j] + sum[i][j] + jin;
			jin = he / 10;
			sum[0][j] = he % 10;
		}
	}

	/* 从后向前找到不为0的第一个数 */
	for (i = MAX - 1; sum[0][i] == 0; i--);

	/* 输出和 */
	for (; i >= 1; i--)
	{
		printf("%d", sum[0][i]);
	}
	printf("\n");

	//system("pause");
	return 0;
}