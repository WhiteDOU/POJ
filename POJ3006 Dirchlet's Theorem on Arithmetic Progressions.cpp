#include <iostream>
#include <cstdio>

using namespace std;


bool mark[1000005];
int prime[1000005];
int loc = 0;


void init()
{
	for (int i = 0; i < 1000005; ++i)
	{
		mark[i] = true;

	}
	mark[0] = mark[1] = false;
	for (int i = 2; i < 1000005; ++i)
	{
		if (mark[i])
		{
			for (int j = 2 * i; j < 1000005; j += i)
			{
				mark[j] = false;
			}
		}
	}
	for (int i = 2; i < 1000005; ++i)
	{
		if (mark[i])
		{
			prime[loc++] = i;
		}
	}
}

int main()
{
	init();
	int a, d, n;
	while (cin >> a >> d >> n && (a != 0 && d != 0 && n != 0))
	{
		int cnt = 0;
	   // cout << a << d << n;
		for (int i = a; i < 1000000; i += d)
		{
			if (mark[i])
			{
				cnt++;
				//cout << cnt << endl;
			}
			if (cnt == n)
			{
				cout << i << endl;
				break;
			}
		}

	}
}