#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int c[8] = {128, 64, 32, 16, 8, 4, 2, 1};
string a;

int convert(int n)
{
	int sum = 0;

	for (int i = n, j = 0; i < n + 8; ++i, j++)
	{
		if (a[i] == '1')
			sum += c[j];
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		cin >> a;
		cout << convert(0) << "." << convert(8) << "." << convert(16) << "." << convert(24) << endl;
	}
	return 0;
}