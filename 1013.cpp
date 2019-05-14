#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Item
{
	int times;
	char c;
	bool right;

	bool operator<(const Item &temp) const
	{
		return abs(times) > abs(temp.times);
	}

} coin[13];

int fake[13];

int main()
{

	int n;
	cin >> n;
	while (n--)
	{
		for (int i = 0; i < 12; ++i)
		{
			coin[i].times = 0;
			coin[i].c = 'A' + i;
			coin[i].right = false;
		}
		for (int j = 0; j < 3; ++j)
		{
			string first;
			string second;
			string status;
			cin >> first >> second >> status;
			switch (status[0])
			{
				case 'e':
				{
					for (int i = 0; i < first.size(); ++i)
					{
						coin[first[i]-'A'].right = true;
						coin[second[i]-'A'].right = true;
					}
					break;
				}
				case 'u':
					for (int i = 0; i < first.size(); ++i)
					{
						coin[first[i]-'A'].times++;
						coin[second[i]-'A'].times--;
					}
					break;
				case 'd':
					for (int i = 0; i < first.size(); ++i)
					{
						coin[first[i]-'A'].times--;
						coin[second[i]-'A'].times++;
					}
					break;

			}

		}
		sort(coin,coin+12);
		for (int i = 0; i < 12; ++i)
		{
			if (!coin[i].right)
			{
				printf("%c is the counterfeit coin and it is %s.\n",coin[i].c,coin[i].times>0?"heavy":"light");
				break;
			}
		}
	}
}