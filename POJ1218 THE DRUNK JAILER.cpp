#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#define MAXN 100
int cell[MAXN+1];

int main()
{
	int t, n, sum, i, j;
	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(cell, 0, sizeof(cell));

		for (i = 2; i <= n; ++i)
		{
			for (j = i; j <= n; j += i)
			{
				cell[j] = 1 - cell[j];
			}
		}
		sum = 0;
		for (i = 1; i <= n; ++i)
		{
			if (cell[i] == 0)
				sum++;
		}
		cout << sum << endl;
	}
}

#include <stdio.h>
#include <math.h>

int main(void)
{
	int t, n, ans;

	scanf("%d",&t);
	while(t--) {
		scanf("%d", &n);

		ans = (int)sqrt(n);

		printf("%d\n", ans);
	}

	return 0;
}