#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;

int cas = 1;
int a,b,c;
int flag = 0;
const int MAXN = 1e2 + 5;
int vis[MAXN][MAXN];
char str[10][10] =
{
	"",
	"FILL(1)",
	"FILL(2)",
	"DROP(1)",
	"DROP(2)",
	"POUR(1,2)",
	"POUR(2,1)"
};

struct Node
{
	int x,y;
	int step;
	char s[1000];
};
void bfs()
{
	queue<Node> q;
	Node p,k;
	p.x = 0,p.y = 0,p.step = 0,p.s[0]='0';
	vis[p.x][p.y] = 1;
	q.push(p);
	while(!q.empty())
	{
		k = q.front();
		q.pop();
		if(k.x==c||k.y == c)
		{
			flag = 1;
			cout <<k.step <<endl;
			for(int i = 0; i<k.step; i++)
			{
				cout <<str[k.s[i]-'0'] <<endl;
			}
			return;
		}
		if(k.x <a)
		{
			p.x = a;
			p.y = k.y;
			p.step = k.step + 1;
			strcpy(p.s,k.s);
			p.s[k.step] = 1+'0';
			if(!vis[p.x][p.y])
			{
				vis[p.x][p.y] = 1;
				q.push(p);
			}
		}
		if(k.y<b)       //把第二个瓶子装满
		{
			p.y=b;
			p.x=k.x;
			p.step=k.step+1;
			strcpy(p.s,k.s);
			p.s[k.step]=2+'0';
			if(!vis[p.x][p.y])
			{
				vis[p.x][p.y]=1;
				q.push(p);
				//printf("%d %d 2\n",p.x,p.y);
			}
		}
		if(k.x!=0)      //把第一个瓶子倒了
		{
			p.x=0;
			p.y=k.y;
			p.step=k.step+1;
			strcpy(p.s,k.s);
			p.s[k.step]=3+'0';
			if(!vis[p.x][p.y])
			{
				vis[p.x][p.y]=1;
				q.push(p);
				//printf("%d %d 3\n",p.x,p.y);
			}
		}
		if(k.y!=0)       //把第二个瓶子倒了
		{
			p.y=0;
			p.x=k.x;
			p.step=k.step+1;
			strcpy(p.s,k.s);
			p.s[k.step]=4+'0';
			if(!vis[p.x][p.y])
			{
				vis[p.x][p.y]=1;
				q.push(p);
				//printf("%d %d 4\n",p.x,p.y);
			}
		}
		if(k.x != 0 &&k.y <b)
		{
			if(b-k.y >=k.x)
			{
				p.y = k.x +k.y;
				p.x = 0;
			}
			else
			{
				p.x = k.x + k.y - b;
				p.y = b;
			}
			p.step = k.step + 1;
			strcpy(p.s,k.s);
			p.s[k.step] = 5 + '0';
			if(!vis[p.x][p.y])
			{
				vis[p.x][p.y] = 1;
				q.push(p);
			}
		}
		if(k.y!=0 && k.x<a)     //把第二个倒进第一个.
		{
			if(a-k.x>=k.y)
			{
				p.x=k.x+k.y;
				p.y=0;
			}
			else
			{
				p.y=k.x+k.y-a;
				p.x=a;
			}
			p.step=k.step+1;
			strcpy(p.s,k.s);
			p.s[k.step]=6+'0';
			if(!vis[p.x][p.y])
			{
				vis[p.x][p.y]=1;
				q.push(p);
				//printf("%d %d 6\n",p.x,p.y);
			}
		}
	}
}



int main()
{
	cin >> a >> b >> c;
	memset(vis,0,sizeof(vis));
	bfs();
	if(!flag)
		cout <<"impossible\n";
}

