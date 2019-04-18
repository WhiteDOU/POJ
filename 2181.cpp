#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int dp[151000][2];

int main()
{
	int p;
	cin >> p;
	dp[0][0] = 0;
	dp[0][1] = 0;
	int temp;
	for (int i = 1; i <= p; ++i)
	{
		cin >> temp;
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - temp);
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + temp);

	}
	cout << max(dp[p][0], dp[p][1]);

}