#include <iostream>
#include <cstdio>

using namespace std;

char maze[21][21];

int go[][2] = {
		0, 1,
		0, -1,
		1, 0,
		-1, 0
};

int sum, w, h;

bool check(int x, int y)
{
	if (x >= 1 && x <= h && y >= 1 && y <= w && maze[x][y] == '.')
		return true;
	return false;
}

void dfs(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int nextx = x + go[i][0];
		int nexty = y + go[i][1];
		if (check(nextx,nexty))
		{
			sum ++;
			maze[nextx][nexty] = '#';
			dfs(nextx,nexty);
		}
	}
}


int main()
{
	while (cin >> w >> h)
	{
		if (w == 0 && h == 0)
			break;
		int x,y;
		sum = 1;
		for (int i = 1; i <= h ; ++i)
		{
			for (int j = 1; j <= w ; ++j)
			{
				cin >> maze[i][j];
				if (maze[i][j] =='@')
				{
					x= i;
					y = j;
				}
			}
		}
		dfs(x,y);
		cout << sum << endl;
	}
}