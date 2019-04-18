#include <iostream>
#include <cstring>

using namespace std;

int ans[22];
bool Hash[22];

int n;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

bool judge(int x)
{
	for (int i = 0; i < 13; ++i)
	{
		if (prime[i] == x)
			return true;
	}
	return false;
}

void check()
{
	if (judge(ans[n] + ans[1]) == false)
		return;
	for (int i = 1; i <= n; ++i)
	{
		if (i != 1)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

void DFS(int num)
{
	if (num > 1)
		if (judge(ans[num] + ans[num - 1]) == false)
			return;
	if (num == n)
	{
		check();
		return;
	}
	for (int i = 2; i <= n; i++)
	{
		if (Hash[i] == false)
		{
			Hash[i] = true;
			ans[num + 1] = i;
			DFS(num + 1);
			Hash[i] = false;
		}
	}

}

int main()
{
	int Case = 0;
	while (cin >> n)
	{
		Case++;
		for (int i = 0; i < 22; ++i)
			Hash[i] = false;
		ans[1] = 1;
		cout << "Case " << Case << endl;
		Hash[1]= true;
		DFS(1);
		cout<<endl;
	}
	return 0;
}