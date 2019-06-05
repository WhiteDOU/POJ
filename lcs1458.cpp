#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <numeric>
#include <sstream>
#include <stack>
#include <map>
#include <queue>
#include<iomanip>

using namespace std;

string a,b;
int dp[1000][1000];
int lcs(string a, string b)
{
	int lenn = a.length();
	int lenm = b.length();
	for (int i = 0; i <= lenm; ++i)
	{
		dp[0][i] = 0;

	}
	for (int i = 0; i <= lenn; ++i)
	{
		dp[i][0] = 0;
	}
	for (int i = 1; i <= lenn ; ++i)
	{
		for (int j = 1; j <= lenm ; ++j)
		{
			if (a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[lenn][lenm];
}

int main()
{
	while (cin >> a >> b)
	{
		cout << lcs(a,b)<<endl;

	}
}