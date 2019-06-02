#include <iostream>
#include <cstring>

using namespace std;


int dp[2][100000];

int main()
{
	bool flag;

	string s, t;
	while (cin >> s >> t)
	{

		int len1 = s.length();
		int len2 = t.length();
		int flag = true;

		int i,j = 0;
		for (i = 0;i < len2;i++)
		{
			if (t[i] == s[j])
				j++;
		}
		if (j >= len1)
			cout <<"Yes"<<endl;
		else
			cout <<"No"<<endl;


	}
}

