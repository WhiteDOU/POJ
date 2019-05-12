#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool mark[1000005];


void init()
{
	for (int i = 0; i < 1000005; ++i)
	{
		mark[i] = true;
	}
	mark[0] = mark[1] = false;
	for (int i = 2; i < 1000005; ++i)
	{
		if (mark[i])
		{

			for (int j = 2 * i; j < 1000005; j += i)
			{
				mark[j] = false;
			}
		}
	}


}

int main()
{
	init();

	int input;
	while (cin >> input && input)
	{
		for (int i = 3; i < 1000005; i+=2)
		{
			if (mark[i] && mark[input - i])
			{
				cout << input << " = " << i << " + " << input - i << endl;
				break;
			}
			if (i > input/2)
				cout <<"Goldbach's conjecture is wrong.\n";
		}

	}

	return 0;
}