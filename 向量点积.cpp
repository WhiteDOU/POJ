#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> temp1;
	vector<int> temp2;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		temp1.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		temp2.push_back(temp);
	}
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += temp1[i] * temp2[i];
	}
	cout << sum;
}