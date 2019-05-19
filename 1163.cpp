#include <iostream>
#include <cmath>
using namespace std;

const int rMax = 101;

int dp[rMax][rMax];

int main()
{
	int row,i,j;
	cin >> row;
	for (i = 1; i <=row ; ++i)
	{
		for (j = 0;j<i;j++)

			cin >> dp[i][j];


	}

	for (i = row - 1; i >=1 ;i--)
	{
		for (j  = 0; j  < i; ++j )
		{
			dp[i][j] +=max(dp[i+1][j],dp[i+1][j+1]);

		}
	}
	cout <<dp[1][0];
}

#include <iostream>
#include <cmath>
using namespace std;

int nums[101][101] = {0};
int lens[101][101] = {0};

int num;
int dfs(int x,int y)
{
	if (lens[x][y]>0)
		return lens[x][y];
	if (x == num)
		return nums[x][y];

	int left = dfs(x+1,y);
	int right = dfs(x+1,y+1);
	int Max = max(left,right);
	lens[x][y] = Max + nums[x][y];
	return lens[x][y];
}

int main()
{
	cin >> num;
	for (int i = 1; i <= num ; ++i)
	{
		for (int j = 1; j <=i ; ++j)
		{
			cin >> nums[i][j];
		}
	}
	cout << dfs(1,1);
	return 0;
}