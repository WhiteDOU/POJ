#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define N 1050
#define INF 0x3f3f3f3f

using namespace std;

int n,d;


struct Point
{
	int x,y;
	double r,l;
	bool init()
	{
		int temp = d*d - y * y;
		if (temp < 0)
			return true;
		l = x - sqrt(temp);
		r = x + sqrt(temp);
		return 0;
	}
	bool operator < (const Point& a)const
	{
		return r < a.r;
	}
}s[N];

int main()
{
	int i,t= 0,flag;
	while ((cin >> n >> d) && !(n == 0 && d == 0))
	{
		cout << "Case "<<++t<<": ";
		flag = 0;
		if (d < 0)
			flag = 1;
		for (int i = 1; i <= n ; ++i)
		{
			cin >> s[i].x >> s[i].y ;
			if (s[i].y<0||s[i].init())
				flag =1;
		}
		if (flag)
		{
			cout << -1 <<endl;
			continue;
		}
		sort(s+1,s+1+n);
		double now = -999999999.9;
		int ans =0;
		for (int i = 1; i <= n ; ++i)
		{
			if (s[i].l<=now)
				continue;
			now = s[i].r;
			ans++;

		}cout << ans << endl;

	}
	return 0;
}