#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXV = 1000;
const int INF = 0x3fffffff;

int n, graph[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};

int prim()
{
	fill(d, d + MAXV, INF);
	d[0] = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int u = -1, MIN = INF;
		for (int j = 0; j < n; ++j)
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)
			return -1;
		vis[u] = true;
		ans += d[u];
		for (int v = 0; v < n; ++v)
		{
			if (vis[v] == false && graph[u][v] != INF && graph[u][v] < d[v])
			{ d[v] = graph[u][v]; }
		}
	}
	return ans;
}

void dj(int s)
{
	fill(d, d + MAXV, INF);
	d[s] = 0;

	for (int i = 0; i < n; ++i)
	{
		int u = -1, MIN = INF;
		for (int j = 0; j < n; ++j)
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)
		{
			return;
		}
		vis[u] = true;
		for (int v = 0; v < n; ++v)
		{
			if (vis[v] == false && graph[u][v] != INF && d[u] + graph[u][v] < d[v])
				d[v] = d[u] + graph[u][v];
		}
	}
}