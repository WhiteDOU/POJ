#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
int prime[3000];
int mark[10005];
int loc = 0;
int dp[10005];

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
			prime[loc++] = i;
			for (int j = 2 * i; j < 10005; j += i)
			{
				mark[j] = false;
			}
		}
	}


}

int main()
{
	init();
	/* for (int i = 0; i < 10005; ++i)
	 {
		 dp[i] = 0;
	 }
	 for (int i = 0; i < 3000; ++i)
	 {
		 dp[prime[i]] = 1;
	 }
	 dp[0] = dp[1] = 0;
	 dp[2] = 1;

	 for (int i = 0; i < 3000; ++i)
	 {
		 int sum = 0;
		 int num = 0;
		 for (int j = 0; j <= i; ++j)
		 {
			 for (int k = j; k <= i; ++k)
			 {
				 sum += prime[k];
				 num++;
			 }
			 if (sum <= 10000 && sum >= 0)
				 dp[sum] = num;
		 }
	 }*/
	int input;
	while (cin >> input && input)
	{
		int l = 0;
		int r = 0;
		int sum = 0;
		int result = 0;
		while (true)
		{
			while (sum < input && r < loc)
			{
				sum += prime[r++];
			}
			if (sum <input)
			{
				break;
			} else if (sum == input)
			{
				result++;
			}
			sum-=prime[l++];
		}
		cout << result << endl;
	}

	return 0;
}