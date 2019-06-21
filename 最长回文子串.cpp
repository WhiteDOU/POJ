#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXV = 100;

char s[MAXV];
int dp[MAXV][MAXV];


int main()
{
	gets(s);
	int len = strlen(s),ans = 1;
	memset(dp,0, sizeof(dp));
	for (int i = 0; i < len; ++i)
	{
		dp[i][i] = 1;
		
		if (i<len-1)
		{
			if (s[i]==s[i+1])
			{
				dp[i][i+1]=1;
				ans = 2;
			}
		}
	}
	for (int l = 3; l <=len ; ++l)
	{
		for (int i = 0; i+l-1<len ; ++i)
		{
			int j = i+l-1;
			if (s[i]==s[j]&&dp[i+1][j-1]==1)
			{
				dp[i][j] = 1;
				ans = l;
			}
		}
	}
	cout << ans;
	return  0;
}