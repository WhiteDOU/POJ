#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	map<int, int> facer;
	map<int, int>::iterator it, it1;
	facer.insert({1000000000, 1});
	int n, id, strength;
	scanf("%d", &n);
	while (n--)
	{
		cin >> id >> strength;
		it = facer.upper_bound(strength);
		if (it == facer.end())
		{
			it--;
			cout << id << it->second << endl;
		} else
		{
			if (it == facer.begin())
			{
				cout << id << it->second << endl;
			} else
			{
				int temp1 = abs(it->first - strength);
				it--;
				int temp2 = abs(it->first - strength);
				if (temp2 <= temp1)
				{
					cout << id << it->second << endl;
				}
				else
				{
					it++;
					cout<< id << it->second << endl;
				}
			}
			facer.insert(pair<int,int>(strength,id));
		}

	}
}