#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>


using namespace std;
const int MAXN = 25;
const int INF = 0x3fffffff;

int maze[MAXN][MAXN],vis[MAXN];
int ans,n;

void dfs(int id,int data)
{
	int temp = data;
	vis[id] = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		if(vis[i] == 0)
		{
			temp +=maze[id][i];
		}
		else
			temp -=maze[id][i];
	}
	ans = max(ans,temp);
	for(int i = id + 1; i <= n;i++)
	{
		if(temp > data)
		{
			dfs(i,temp);
			vis[i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin >> n)
	{
		
		for(int i = 1 ; i <= n ;i++)
			for(int j = 1;j <= n;j++)
				cin >> maze[i][j];
		memset(vis,0,sizeof(vis));
		ans = -INF;
		dfs(1,0);
		cout << ans <<endl;
	}
	return 0;
}