#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
const int maxn = 2200;
vector<int> G[maxn];
int color[maxn];

int n, m;

bool dfs(int u, int c)
{
	color[u] = c;
	for (int i = 0; i < G[u].size(); ++i)
	{
		if (color[G[u][i]] == c)
			return false;
		if (color[G[u][i]] == 0 && !dfs(G{u}[i], -c))
			return false;
	}
	return true;
}

void solve()
{
	for (int i = 1; i <= n; ++i)
	{
		if (color[i] == 0)
		{
			if (!dfs(i, 1))
			{
				printf("Suspicious bugs found!\n\n");
				return;
			}
		}
	}
	printf("No suspicious bugs found!\n\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	int u, v;
	int kase = 0;
	cin >> T:
	while (T--)
	{
		memset(color,0, sizeof(color));
		cin >> n >> m;
		for (int i = 0; i <= n ; ++i)
		{
			G[i].clear();
		}
		while (m--)
		{
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		printf("Scenario #%d:\n", ++kase);
		solve();
	}

}