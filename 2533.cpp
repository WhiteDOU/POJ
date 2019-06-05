#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <numeric>
#include <sstream>
#include <stack>
#include <map>
#include <queue>
#include<iomanip>

using namespace std;

int n ;
int input [1005];
int dp[1005];
int LOS()
{
	dp[0] = 1;
	for (int i = 1; i <n ; ++i)
	{
		int ans = 1;
		for (int j = i-1; j >=0 ; --j)
		{
			if (input[i]>input[j])
			{
				ans = max(ans,dp[j]+1);
			}
			dp[i] = ans;

		}
	}
	int ret =1;
	for (int i = 0; i < n; ++i)
	{
		ret = max(ret,dp[i]);
	}
	return  ret;

}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
	cout << LOS();


}