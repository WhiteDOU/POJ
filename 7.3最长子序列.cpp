#include <iostream>

using namespace std;


int list[26];
int dp[26];

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; ++i)
		{
			cin >> list[i];
			
		}
		for (int i = 1; i <= n; ++i)
		{
			int tmax = 1;

			for (int j = 1; j < i; ++j)
			{
				if (list[j] >= list[i])
				{
					tmax = max(tmax, dp[j] + 1);
				}
			}
			dp[i] = tmax;
		}
		int ans = 1;
		for (int i = 1; i <= n; ++i)
		{
			ans = max(ans, dp[i]);
			cout << dp[i] << " ";
		}
		cout << ans << endl;
	}
	return 0;
}