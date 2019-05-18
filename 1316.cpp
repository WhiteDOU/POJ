#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


bool judge[10005];

int main()
{
	judge[0] = true;
	judge[1] = false;
	judge[2] = true;

	for (int i = 2; i < 10005; ++i)
	{
		int sum = 0;
		sum +=i;
		int temp = i;
		while (temp)
		{
			int last = temp % 10;
			temp /= 10;
			sum +=last;
		}
		judge[sum] = true;
	}

	for (int j = 0; j < 10000; ++j)
	{
		if (judge[j]== false)
			cout << j << endl;
	}
}