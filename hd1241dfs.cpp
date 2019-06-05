#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <numeric>
#include <sstream>
#include <stack>
#include <map>
#include <queue>
#include<iomanip>

using namespace std;


int go[][2] =
	{
		1, 0,
		-1, 0,
		0, 1,
		0, -1,
		1, 1,
		-1, 1,
		-1, -1,
		1, -1,
	};
char maze[110][110];
bool vis[110][110];
void dfs(int x, int y)
{
	if (maze[x][y]=='*')
		return;
	if(maze[x][y]=='@')
	{
		vis[x][y] = true;
		for (int i = 0; i < 8; ++i)
		{
			int next_x = x + go[i][0];
			int next_y = y + go[i][1];
			if (maze[next_x][next_y]=='@'&&!vis[next_x][next_y])
			{
				dfs(next_x,next_y);
			}
		}
	}
}

int main()
{
	int n ,m;

	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> maze[i][j];
			}
		}
		memset(vis,0, sizeof(vis));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(maze[i][j] == '@'&&!vis[i][j])
				{
					cnt ++ ;
					dfs(i,j);
				}
			}
		}
		cout << cnt <<endl;
	}
	return 0;
}