#include <iostream>
#include <stack>
#include <queue>

using namespace std;

const int MAX_N = 105;
const int MAX_M = 105;

int n, m;
bool mark[MAX_N][MAX_N];
int maze[MAX_N][MAX_N];

int go[][2] = {
		1, 0,
		-1, 0,
		0, 1,
		0, -1
};
struct N
{
	int x;
	int y;
	int t;
};
queue<N> Q;

int bfs(int x, int y)
{
	while (!Q.empty())
	{
		N temp = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = temp.x + go[i][0];
			int ny = temp.y + go[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if (mark[nx][ny])
				continue;
			if (maze[nx][ny]==1)
				continue;

			mark[nx][ny]= true;

			N newNode;
			newNode.x=nx;
			newNode.y=ny;
			newNode.t=temp.t+1;
			Q.push(newNode);
			
			if (newNode.x==x&&newNode.y==y)
				return newNode.t;
		}
	}
	return 1;
}

int main()
{
	return 0;
}
