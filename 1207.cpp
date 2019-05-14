#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
	int first, second;
	while (cin >> first >> second)
	{
		int ans;
		int cur = 0;
		int i;
		int pfirst = first;
		int psecond = second;
		if (first > second)
			swap(pfirst,psecond);
		for (i = pfirst; i <= psecond; ++i)
		{
			int temp = i;
			int num = 0;
			while (true)
			{
				num++;
				if (temp == 1)
					break;
				if (temp % 2 == 1)
					temp = 3 * temp + 1;
				else if (temp % 2 == 0)
					temp = temp / 2;
			}
			if (num > cur)
			{
				cur = num;
				ans = i;
			}
		}
		cout << first << " " << second << " " << cur << endl;
	}
	return 0;
}