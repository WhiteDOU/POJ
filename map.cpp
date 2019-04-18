#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <iostream>

using namespace std;
map<string, int> M;
int in[2002];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < 2 * n; ++i)
		{
			int[i]=0;
		}
		M.clear();
		int index = 0;
		for (int i = 0; i < n; ++i)
		{
			char str1[50], str2[50];
			cin >> str1 >> str2;
			string a = str1, b = str2;
			int index_a, index_b;
			if (M.find(a) == M.end())
			{
				index_a = index;
				M[a] = index++;
			} else
				index_a = M[a];
			if (M.find(b) == M.end())
			{
				index_b = index;
				M[b] = index++;
			} else
				index_b=M[b];
			in[index_b]++;

		}
		int cnt=0;
		for (int i = 0; i < index; ++i)
		{
			if (in[i]==0)
				cnt++;
		}
		cout<<(cnt==1?"Yes":"No")
	}
	return 0;
}