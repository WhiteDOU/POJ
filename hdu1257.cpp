#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 0x3fffffff

int a[10005];
int dp[10005];


int main()
{
	int n ;
	while (cin >> n)
	{
		memset(dp,INF, sizeof(dp));
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		dp[0] = 1;
		int c= 0;
		for (int i = 0; i < n; ++i)
		{
			int flag = 0;
			for (int j = 0; j < c; ++j)
			{
				if (dp[j] >=a[i])
				{

					dp[j] = a[i];
					flag = 1;
					break;
				}
			}
			if (!flag)
				dp[c++] = a[i];
		}
		cout << c << endl;

	}
}