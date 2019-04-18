#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int vis[105][105];
char s[105][105];
int m, n, k, sx, sy, ex, ey;
int direction, flag;
struct Position
{
	int x, y;
};

Position dir[4] = {{0,  1},
				   {1,  0},
				   {0,  -1},
				   {-1, 0}};

bool in(int a, int b)
{
	if (a > 0 && a <= n && b > 0 && b <= n && s[a][b] != '*')
		return true;
	else
		return false;
}

void DFS(int row, int col, int direction, int cnt)
{
	if (cnt > k)
		return;
	if (row == ex && col == ey)
	{
		flag = 1;
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		int x = row + dir[i].x;
		int y = col + dir[i].y;
		if (in(x, y))
		{
			if (direction == 0)
			{
				direction = i + 1;
				cnt++;
			}
			if (direction != i + 1)
				cnt++;
			vis[row][col] = 1;
			DFS(x, y, direction, cnt);
			if (direction != i + 1)
				cnt--;
			vis[row][col] = 0;

		} else
			continue;
	}
}

struct Node
{
	int x, y, k;
};
int dir2[][2] =
		{
				-1, 0,
				1, 0,
				0, -1,
				0, 1
		};

void BFS()
{
	Node t;
	t.x = sx;
	t.y = sy;
	t.k = -1;
	vis[sx][sy] = 1;
	queue<Node> Q;
	Q.push(t);
	while (!Q.empty())
	{
		Node t1 = Q.front();
		Q.pop();
		if (t1.k == ex && t1.y == ey && t1.k <= k)
		{
			flag = true;
		}
		for (int i = 0; i < 4; ++i)
		{
			Node t2;
			t2.x = t1.x + dir2[i][0];
			t2.y = t2.y + dir2[i][1];
			while (t2.x >= 1 && t2.x <= n && t2.y >= 1 && t2.y <= m && s[t2.x][t2.y]!='*')
			{
				if (vis[t2.x][t2.y] == 0)
				{
					t2.k = t1.k + 1;
					vis[t2.x][t2.y] = 1;
					Q.push(t2);
				}
				Node t3;
				t3.x = t2.x + dir[i][0];
				t3.y = t2.y + dir[i][1];
				t2 = t3;
			}
		}
	}
}

int main()
{
	int icase;
	scanf("%d", &icase);
	while (icase--)
	{
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &m, &n);


		for (int i = 1; i <= m; i++)
			scanf("%s", s[i]);


		scanf("%d%d%d%d%d", &k, &sy, &sx, &ey, &ex);
		flag = 0;
		DFS(sx, sy, 0, -1);
		printf("%s\n", flag == 0 ? "no" : "yes");
	}
	return 0;
}
