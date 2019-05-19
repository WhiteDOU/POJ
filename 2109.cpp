#include <cmath>
#include <iostream>

using namespace std;


int main()
{
	double n,p;
	while (cin >> n >> p)
	{
		cout << pow(double(p),1/n) << endl;
	}
}

#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
	double n, m;
	long long left, right, mid;
	while (cin >> n >> m)
	{
		left = 0;
		right = 1000000002;
		while (right - 0.00000001 > left)
		{
			mid = (left + right) / 2;
			if (pow(mid, n) - m > 0)
				right = mid;
			else if (pow(mid, n) - m < 0)
				left = mid;
			else
			{
				cout << mid<<endl;
				break;
			}
		}
	}
}