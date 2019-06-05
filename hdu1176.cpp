#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 9999 + 5;
int dp[MAXN][15];

int main()
{
	int n;
	while (cin >> n && n)
	{
		memset(dp, 0, sizeof(dp));
		int a, b, t = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a >> b;
			dp[b][a + 1]++;
			t = max(t, b);
		}
		for (int i = t - 1; i >= 0; --i)
		{
			for (int j = 11; j >= 1; --j)
			{
				dp[i][j] += max(dp[i + 1][j], max(dp[i - 1][j - 1], dp[i - 1][j + 1]));
			}
		}
		cout << dp[0][6];
	}
}