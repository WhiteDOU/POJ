#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int n ;
queue<long long> q;
int main()
{
	while(cin >>n)
	{
		if(n == 0)
			break;
		while(!q.empty())
			q.pop();
		q.push(1);
		while(!q.empty())
		{
			long long now = q.front();
			q.poap();
			long long nex = now * 10;
			if(nex% n == 0)
			{
				cout <<nex<<endl;
				break;
			}
			q.push(nex);
			nex ++;
			if(nex % n == 0)
			{
				cout << nex <<endl;
				break;
			}
			q.push(nex);
		}
	}
}