#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> input;

int main()
{
	while (true)
	{
		int temp;
		input.clear();
		int sum = 0;
		while (cin >> temp && temp != 0)
		{
			input.push_back(temp);
		}
		sort(input.begin(), input.end());
		for (int i = 0; i < input.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (input[j] * 2 == input[i])
				{
					sum++;
					break;
				}
			}
		}
		if (temp == -1)
			break;
		else
			cout << sum << endl;
	}
}