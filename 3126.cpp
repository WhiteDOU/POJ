#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

bool isPrime[10000];
bool vis[10000];

void init()
{
	for(int i = 0; i < 10000 ; i ++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;

	for(int i = 2; i < 10000 ; i ++)
	{
		if(isPrime[i])
		{
			for(int j = 2 * i; j <10000 ; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

}
struct Point
{
	int num;
	int step;
};
queue<Point> q;
int st,ed;
int bfs(int st,int ed)
{
	//memset(vis,0,sizeof(vis));
	Point startPoint;
	startPoint.num = st;
	startPoint.step = 0;

	q.push(startPoint);
	vis[startPoint.num] = true;
	while(!q.empty())
	{
		Point temp = q.front();
		q.pop();
		if(temp.num==ed)
		{
			return temp.step;
		}
		int ge = temp.num % 10;
		int shi = (temp.num / 10) % 10;
		int bai = (temp.num/100) % 10;
		int qian = (temp.num/1000) ;
		int numtemp;
		Point next;
		for(int i = 1 ; i<=9; i+=2)
		{
			numtemp = qian * 1000 + bai* 100+shi*10+i;
			if(isPrime[numtemp] && !vis[numtemp])
			{
				next.num = numtemp;
				next.step = temp.step + 1;
				q.push(next);
				vis[next.num] = true;
			}
		}
		for(int i = 0 ; i<=9; i++)
		{
			numtemp = qian * 1000 + bai* 100+i*10+ge;
			if(isPrime[numtemp] && !vis[numtemp])
			{
				next.num = numtemp;
				next.step = temp.step + 1;
				q.push(next);
				vis[next.num] = true;
			}
		}
		for(int i = 0 ; i<=9; i++)
		{
			numtemp = qian * 1000 + i* 100+shi*10+ge;
			if(isPrime[numtemp] && !vis[numtemp])
			{
				next.num = numtemp;
				next.step = temp.step + 1;
				q.push(next);
				vis[next.num] = true;
			}
		}
		for(int i = 1 ; i<=9; i++)
		{
			numtemp = i* 1000 + bai* 100+shi*10+ge;
			if(isPrime[numtemp] && !vis[numtemp])
			{
				next.num = numtemp;
				next.step = temp.step + 1;
				q.push(next);
				vis[next.num] = true;
			}
		}
	}
	return -1;

}
int main()
{
	init();
	int n ;
	cin >>n;
	while(n--)
	{
		while(!q.empty())
			q.pop();
		memset(vis,0,sizeof(vis));
		cin >> st >>ed;
		int ans = bfs(st,ed);
		if(ans == -1)
			cout << "Impossible" << endl;
		else
			cout <<ans<<endl;
	}
}
