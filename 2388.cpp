#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main()
{
	vector<int> temp;
	int n;
	int times;
	cin >> n;
	times = n;
	while (n--)
	{
		int t;
		cin >> t;
		temp.push_back(t);
	}
	sort(temp.begin(),temp.end());

	cout << temp[times/2];
}