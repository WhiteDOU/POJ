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
struct Node
{
	int x, y;
	int time;

};
int maze[6][6];
bool vis[6][6];
Node father[6][6];


int go[][2] = {
		1, 0,
		-1, 0,
		0, 1,
		0, -1
};
queue<Node> q;

bool check(Node node)
{
	int x = node.x;
	int y = node.y;
	if (x < 1 || x > 5 || y < 1 || y > 5)
	{
		return false;
	}
	return true;
}
vector<Node> temp;


void bfs()
{
	Node node;
	node.x = 1;
	node.y = 1;
	node.time = 0;

	q.push(node);
	vis[node.x][node.y] = true;
	while (!q.empty())
	{
		Node temp;
		temp = q.front();
		q.pop();
		if (temp.x == 5 && temp.y == 5)
		{

			return;
		}
		Node nodenew;
		for (int i = 0; i < 4; ++i)
		{
			nodenew.x = temp.x + go[i][0];
			nodenew.y = temp.y + go[i][1];
			nodenew.time = temp.time + 1;
			if (check(nodenew)&&!vis[nodenew.x][nodenew.y]&&maze[nodenew.x][nodenew.y]==0)
			{
				q.push(nodenew);
				vis[nodenew.x][nodenew.y] = true;
				father[nodenew.x][nodenew.y] = temp;
			}
		}
	}
}

int main()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cin >> maze[i][j];
		}
	}
	bfs();
	Node endPoint = father[6][6];

	while (!(endPoint.x==0 && endPoint.y == 0))
	{
		cout << endPoint.x<<" "<<endPoint.y<<endl;
		endPoint=father[endPoint.x][endPoint.y];
	}
	Node node;
	node.x = 5;
	node.y = 5;
	temp.push_back(node);
	while (!(node.x==1 && node.y == 1))
	{
		node = father[node.x][node.y];
		temp.push_back(node);
	}
	for (int i = temp.size()-1; i >=0 ; --i)
	{
		cout <<"("<< temp[i].x -1 <<", "<<temp[i].y-1<<")"<<endl;
	}
}