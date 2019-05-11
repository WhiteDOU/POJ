#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
	string one;
	string two;
	cin >> one;
	cin >> two;
	vector<int> vecotrOne(26, 0);
	vector<int> vectorTwo(26, 0);
	if (one.size() != two.size())
		cout << "NO";
	for (int i = 0; i < one.size(); ++i)
	{
		vecotrOne[one[i] - 'A']++;
	}
	for (int i = 0; i < one.size(); ++i)
	{
		vectorTwo[two[i] - 'A']++;
	}
	sort(vecotrOne.begin(),vecotrOne.end());
	sort(vectorTwo.begin(),vectorTwo.end());
	if (vecotrOne == vectorTwo)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}