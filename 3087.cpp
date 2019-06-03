#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;

typedef long long ll;

map<string,int> mp;
int n;
string tar;
string trans(string s1,string s2)
{
	string s12 = "";
	for(int i = 0; i < n;i++)
	{
		s12+=s2[i];
		s12 +=s1[i];
	}
	return s12;
}

int bfs(string s1,string s2)
{
	queue<string> q;
	string s12 = trans(s1,s2);
	mp[s12] = 1;
	q.push(s12);
	while(!q.empty())
	{
		string now = q.front();
		q.pop();
		if(now == tar)
			return mp[now];
		s1 = now.substr(0,n);
		s2 = now.substr(n,n);
		s12 = trans(s1,s2);
		if(mp[s12]>0)
			return -1;
		mp[s12] =mp[now]+1 ;
		q.push(s12);
	}
	return -1;
}

int main()
{
	int T,res = 1;
	string s1,s2;
	cin >>T;
	while(T--)
	{
		
		mp.clear();
		cin >> n;
		cin >> s1 >> s2 >>tar;
		int ans = bfs(s1,s2);
		cout <<res++<<" "<<ans << endl;
	}
}
