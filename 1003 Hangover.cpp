#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	double n;
	while (cin >> n && n !=0.00)
	{
		double sum = 0;
		int cnt = 0;
		double i = 2;
		while (sum <n)
		{
			sum += 1/i;
			i++;
			cnt++;
		}
		cout <<cnt<<" card(s)"<<endl;
	}

}