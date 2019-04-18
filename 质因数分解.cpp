#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x)
{
	for (int i = 2; i*i <=x ; ++i)
	{
		if(x%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	int i = sqrt(n);
	for (int i = sqrt(n); i <n ; ++i)
	{
		if (i * (n/i) == n && isPrime(i) && isPrime(n/i))
			cout << i;
	}
}