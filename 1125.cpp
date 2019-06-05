#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3fffffff;

int maze[105][105];
int d[105][105];

int n;

void floyd()
{
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}

int main()
{
	int num;
	int temp;
	while (cin >> n && n)
	{
		memset(d, INF, sizeof(d));

		for (int i = 1; i <= n; ++i)
		{
			cin >> num;
			while (num--)
			{
				cin >> temp;
				cin >> d[i][temp];
			}

		}
		floyd();
		

	}

}