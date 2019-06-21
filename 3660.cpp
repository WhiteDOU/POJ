#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;


const int N = 109;
const int MAX = 0x3f3f3f3f;
bool v[N][N];

int main()
{
	int n,m;
	cin >> n >>m;
	memset(v,0, sizeof(v));
	for (int i = 1; i <= m ; ++i)
	{
		int a,b;
		cin >> a>> b;
		v[a][b] = 1;
	}
	for (int i = 1; i <= n ; ++i)
	{
		for (int j = 1; j <= n ; ++j)
		{
			for (int k = 1; k <=n ; ++k)
			{
				v[k][j]|=v[k][i]&&v[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n ; ++i)
	{
		int cnt = 0;
		for (int j = 1; j <= n ; ++j)
		{
			if (v[j][i])
				cnt ++;
			if (v[i][j])
				cnt++;
		}
		if (cnt == n-1)
			ans++;
	}
	cout <<ans;
}