
#include<stdio.h>
#include<iostream>

using namespace std;
int chess[4][4];
int c = 33;


void build()//将棋盘的颜色以标记化
{
	char c;
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			cin >> c;
			if (c == 'w')
				chess[i][j] = 0;
			else
				chess[i][j] = 1;
		}
}

void turn(int x, int y)//翻转
{
	if (x >= 0 && x <= 3 && y >= 0 && y <= 3)
		chess[x][y] = !chess[x][y];
}

void flip(int s)//一个棋子变化，周围四个都要变化
{
	int i = s / 4;//行
	int j = s % 4;//列
	turn(i, j);
	turn(i + 1, j);
	turn(i, j + 1);
	turn(i - 1, j);
	turn(i, j - 1);
}

int complete()//判断棋盘是否变成同一的颜色
{
	int i, j, s1 = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			s1 += chess[i][j];
	if (s1 % 16)
		return 0;
	else
		return 1;
}

void dfs(int s,int b) //s代表当前的方格，b代表反转的方格数
{
	if (complete())
	{
		if (c > b)
			c=b;
		return;
	}
	if (s >= 16)
		return;
	dfs(s+1,b);
	flip(s);
	dfs(s+1,b+1);
	flip(s);
	
}
int main()
{
	build();
	dfs(0,0);
	if (c == 33)
		cout<<"Impossible\n";
	else
		cout<<c<<endl;
	return 0;
}