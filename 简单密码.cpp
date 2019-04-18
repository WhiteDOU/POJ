#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
char ans[26];
char tureOrder[26];
void init()
{
	for (int i = 0; i <26 ; ++i)
	{
		tureOrder[i] =char('A'+i);
	}
	for (int i = 0; i < 26; ++i)
	{
		int index = (i-5) % 26;
		if (index==0)
			index = 21;
		else if (index<0)
			index+=26;
		else
			index=index;
		ans[i]=tureOrder[index];

	}

}

char trans(char a)
{
	if (!(a>='A'&&a<='Z'))
		return a;
	else
		return ans[a-'A'];
}
int main()
{
	init();
	string temp;
	getline(cin,temp);
	for (int i = 0; i < temp.size(); ++i)
	{
		cout<<trans(temp[i]);
	}
}