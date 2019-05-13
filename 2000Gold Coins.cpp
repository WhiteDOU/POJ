#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	while (cin >> t && t != 0)
	{
		int sum = 0;
		int times = t;

		for (int i = 1; i <= t; ++i)
		{
			int temp = i;
			while (temp && times)
			{
				sum += i;
				temp--;
				times--;
			}
		}
		cout <<  t << " " << sum << endl;
	}
} 