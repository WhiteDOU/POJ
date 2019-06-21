#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3fffffff;

set<int> set1;
int maze[10][10];


int go[][2] =
		{
				0, 1,
				0, -1,
				1, 0,
				-1, 0
		};

void dfs(int x, int y, int len, int num)
{
	if (len == 6)
	{
		set1.insert(num);
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		int nextx = x + go[i][0];
		int nexty = y + go[i][1];
		if (nextx > 0 && nextx <= 5 && nexty > 0 && nexty <= 5)
		{
			dfs(nextx, nexty, len + 1, num * 10 + maze[nextx][nexty]);
		}
	}
}


int main()
{
	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 1; j <= 5; ++j)
		{
			cin >> maze[i][j];
		}
	}
	for (int i = 1; i <= 5 ; ++i)
	{
		for (int j = 1; j <=5 ; ++j)
		{
			dfs(i,j,1,maze[i][j]);
		}
	}
	cout << set1.size();
	return 0;
}