#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


char a[11][11];
bool book[11];
int n, k;
int ans, m;

void dfs(int cur)
{
	if (k == m)
	{
		ans++;
		return;
	}
	if (cur >= n )
		return;
	for (int i = 0; i < n; ++i)
	{
		if (book[i] == false && a[cur][i] == '#')
		{
			book[i] = true;
			m++;
			dfs(cur + 1);
			book[i] = false;
			m--;
		}
	}
	dfs(cur + 1);

}

int main()
{
	int i, j;
	while (cin >> n >> k)
	{
		if (n == -1 && k == -1)
			break;
		ans = 0;

		m = 0;
		for (int i = 0; i <n; ++i)
		{
			cin >> a[i];
		}
		memset(book, 0, sizeof(book));

		dfs(0);
		cout << ans << endl;
	}


}