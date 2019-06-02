#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int r,n,m;
string s[35][35];
struct node
{
	int x,y,z;
	int t;
};
node Begin,End;
queue <node> que;
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {1,-1,0,0,0,0};
int vis[35][35][35];
int bfs()
{
	que.push(Begin);
	vis[Begin.x][Begin.y][Begin.z] = 1;
	while(!que.empty())
	{
		node front = que.front();
		que.pop();
		if (front.x == End.x && front.y == End.y && front.z == End.z) return front.t;
		for (int i = 0; i < 6; i++)
		{
			node tmp;
			tmp.x = front.x + dx[i];
			tmp.y = front.y + dy[i];
			tmp.z = front.z + dz[i];
			tmp.t = front.t + 1;
			if (tmp.x >= 0 && tmp.x < r && tmp.y >= 0 && tmp.y < n && tmp.z >= 0 && tmp.z < m && !vis[tmp.x][tmp.y][tmp.z] && s[tmp.x][tmp.y][tmp.z] != '#')
			{
				que.push(tmp);
				vis[tmp.x][tmp.y][tmp.z] = 1;
			}
		}
	}
	return -1;
}
int main()
{
	while(cin >> r >> n >> m)
	{
		if (r == 0 && n == 0 && m == 0) break;
		memset(vis,0,sizeof(vis));
		while(!que.empty())
		{
			que.pop();
		}
		for (int i = 0; i < r; i++){
			string ret;
			for (int j = 0; j < n; j++){
				cin >> s[i][j];
				for (int k = 0; k < m; k++){
					if (s[i][j][k] =='S'){
						Begin.x = i,Begin.y = j,Begin.z = k;Begin.t = 0;
					}
					else if (s[i][j][k] == 'E'){
						End.x = i,End.y = j,End.z = k;End.t= 0;
					}
				}
			}
		}
		int ans = bfs();
		if (ans == -1){
			printf("Trapped!\n");
		}
		else{
			printf("Escaped in %d minute(s).\n",ans);
		}
	}

	return 0;
}
