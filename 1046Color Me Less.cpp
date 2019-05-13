#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Color
{
	int r;
	int g;
	int b;
};
Color test[17];

int main()
{
	int i, j, k, x, y, z, sum;
	for (i = 0; i < 16; i++)
	{
		cin >> test[i].r >> test[i].g >> test[i].b;
	}
	while (cin >> x >> y >> z)
	{
		if (x == -1 && y == -1 && z == -1)
			break;
		sum = 0x3fffffff;
		for (i = 0; i < 16; i++)
		{
			j = (x - test[i].r)*(x - test[i].r)+(y-test[i].g)*(y-test[i].g)+(z-test[i].b)*(z-test[i].b);
			if (j < sum)
			{
				sum = j;
				k = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",x,y,z,test[k].r,test[k].g,test[k].b);
	}
	return 0;
}