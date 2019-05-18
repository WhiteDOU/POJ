#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


bool judge[10005];

int main()
{
	int n;
	cin >> n;
	int time = 1;
	while (n--)
	{
		int ansl = 0;
		int ansr = 0;
		int x, y;
		cin >> x >> y;
		while (!(x == 1 & y == 1))
		{
			if (x > y)
			{
				ansl +=(x-1)/y;
				x = x % y;
				if (x == 0)
					x = 1;
			} else if (y > x)
			{
				ansr +=(y-1)/x;
				y = y % x;
				if (y == 0)
					y = 1;
			}
		}
		cout << "Scenario #"<<time<<":"<< endl;
		cout << ansl << " " << ansr << endl << endl;

		time++;
	}
}