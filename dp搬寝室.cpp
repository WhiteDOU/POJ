#include <cstdio>
#include <iostream>

using namespace std;

#define INF 0x7fffffff;

int list[2001];
int dp[2001][2001];

int main()
{
	int n, k;
	while (cin >> n >> k)
	{

		for (int i = 1; i <= n; ++i)
		{
			cin >> list[i];
		}

		sort(list + 1, list + 1 + n);
		for (int i =1; i <= n; ++i)
		{
			dp[0][i] = 0;
		}
		for (int i = 1; i <= k; ++i)
		{
			for (int j = 2 * i; j <= n; ++j)
			{
				if (j > 2 * i)
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = INF;
				if (dp[i][j] > dp[i - 1][j - 2] + (list[j] - list[j - 1]) * (list[j] - list[j - 1]))
					dp[i][j] = dp[i - 1][j - 2] + (list[j] - list[j - 1]) * (list[j] - list[j - 1]);

			}
		}
		cout<<dp[k][n]<<endl;
	}
}
