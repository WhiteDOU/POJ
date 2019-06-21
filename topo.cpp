#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXV = 100;
vector<int> graph[MAXV];
int n;
int m,inDegree[MAXV];
bool topo()
{
	int num = 0;
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < graph[u].size(); ++i)
		{
			int v = graph[u][i];
			inDegree[v]--;
			if (inDegree[v]==0)
				q.push(v);
		}
		graph[u].clear();
		num ++;
	}
	if (num == n)
		return true;
	else
		return false;
}