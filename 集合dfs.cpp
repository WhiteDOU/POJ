#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 10005;
int n;
int input[MAXN];
bool vis[MAXN];
vector<int> temp;
vector<vector<int> > output;

int ans;

void dfs(int index, int sum)
{
	if (index == n)
	{
		int tempsum = 0;
		for (int i = 0; i < temp.size(); ++i)
		{
			sum += temp[i];
		}
		if (sum % n == 0)
			output.push_back(temp);
		return;
	}
	dfs(index + 1, sum);
	temp.push_back(input[index]);
	dfs(index + 1, sum + input[index]);
	temp.pop_back();


}


int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
	dfs(0, 0);

	cout << output[3].size() << endl;
  //  sort(output[1].begin(), output[1].end());
//    for (int i = 0; i < output.size(); ++i)
//    {
//        for (int j = 0; j < output[i].size(); ++j)
//        {
//            cout << output[i][j] << " ";
//        }
//        cout << endl;
//    }
	for (int i = 0; i < output[3].size(); ++i)
	{
		if (output[1][i]!=0)
		cout << output[1][i] << endl;
	}

}