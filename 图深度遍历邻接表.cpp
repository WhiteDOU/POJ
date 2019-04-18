#include <algorithm>
#include <iostream>

using  namespace std;

const int MAX_V = 1000;
const  int INF = -1;
int n,G[MAX_V][MAX_V];

bool vis[MAX_V] = {false};

void DFS(int u,int depth)
{
	vis[u] = true;
	for (int i = 0; i < n; ++i)
	{
		if (vis[i] == false && G[u][i] != INF)
			DFS(i ,depth + 1);
	}
}

void DFSTrave()
{
	for (int i = 0; i < n; ++i)
	{
		if (vis[i] == false)
			DFS(i ,1);
	}
}