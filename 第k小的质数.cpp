#include <iostream>
#include <vector>


using namespace std;

int prime[10005];
bool mark[10005];
int size = 0;

void init()
{
	for (int i = 0; i < 10005; ++i)
	{
		mark[i] = true;
	}
	mark[0] = mark[1] = false;

	for (int i = 2; i < 10005; ++i)
	{
		if (mark[i])
		{
			for (int j = 2*i; j <10005 ; j += i)
			{
				mark[j] = false;
			}
		}
	}
	for (int i = 2; i <10005 ; ++i)
	{
		if (mark[i])
			prime[size++] = i;
	}
}
int main()
{
	init();
	int n ;
	cin >> n;
	cout << prime[n-1];
}