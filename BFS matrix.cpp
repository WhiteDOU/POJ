#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;


const int maxn = 2010;
const int INF = -1;
map<int, string> intToString;
map<string, int> Gang;

int n ,G[maxn][maxn];
bool inq[maxn] = {false};

void BFS(int u)
{
	queue<int> Q;
	Q.push(u);
	inq[u] = true;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < n; ++i)
		{
			if (inq[i] = false && G[u][i] != INF)
			{
				Q.push(i);
				inq[i] = true;
			}
						
		}
	}
}

void BFSTrave()
{
	for (int i = 0; i < n; ++i)
	{
		if (inq[i] == false)
			BFS(i);
			
	}
}

