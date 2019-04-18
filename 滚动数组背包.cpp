#include <cstdio>
#include <iostream>

#define INF 0x7fffffff

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

struct E
{
	int w;
	int v;
} list[101];

int dp[1001];

int main()
{
	int s, n;
	while (cin >> s >> n)
	{
		for (int i = 1; i <= n; ++i)
		{
			cin >> list[i].w >> list[i].v;
		}
		for (int i = 0; i <=s ; ++i)
		{
			dp[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for (int j = s; j >=list[i].w ; --j)
			{
				dp[j]=max(dp[j],dp[j-list[i].w]+list[i].v);
			}
		}
		cout<<dp[s]<<endl;
	}
}
