#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int mont = 12;
double balance,average,total;
int main()
{
	for (int i = 0; i < 12; ++i)
	{
		cin >> balance;
		total +=balance;
	}
	average = total/12;
	printf("$%.2lf\n",average);

}