#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

const int N = 26;
string s1, s2;

void findPost(int root, int left, int right)
{
	if (left > right)
		return;
	int i;
	for (i = 0; i <=right && s2[i]!=s1[root] ; ++i)
	{

	}
	findPost(root+1,left,i-1);
	findPost(root+i-left+1,i+1,right);
	cout << s2[i];
}


int main()
{
	while (cin >> s1 >> s2)
	{
		findPost(0,0,s1.size()-1);
		cout << endl;
	}
	return 0;
}
