#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

const int N = 2009;
int dp[N][N];
int a[N];

int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j+i<=n; j++)
			if(i == 0 && j == 0)
				dp[i][j] = 0;
			else if(j == 0)
				dp[i][j] = dp[i-1][j] + a[i]*(i+j);
			else if(i == 0)
				dp[i][j] = dp[i][j-1] + a[n-j+1]*(i+j);
			else
				dp[i][j] = max(dp[i-1][j] + a[i]*(i+j),
							   dp[i][j-1] + a[n-j+1]*(i+j));
	}
	int ans = 0;
	for(int i=0; i<=n; i++)
		ans = max(ans, dp[i][n-i]);
	cout<<ans<<endl;
	return 0;
}
