
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10010;
int num[maxn];
int mod[maxn];
int sum[maxn];
int main()
{
	int n;
	cin>>n;
	memset(mod, -1 ,sizeof(mod));
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		if(i>0)
			sum[i]=sum[i-1]+num[i];
		else
			sum[i]=num[i];
	}
	int sign=0;
	for(int i=0;i<n;i++)
	{
		if(sum[i]%n==0)
		{
			sign=1;
			cout<<i+1<<endl;
			for(int j=0;j<=i;j++)
				cout<<num[j]<<endl;
			break;
		}
		if(mod[sum[i]%n]!=-1)//如果被赋值过了，则说明遇到相同的余数了；
		{
			int tm=i-mod[sum[i]%n];
			cout<<tm<<endl;
			for(int j=mod[sum[i]%n]+1;j<=i;j++)
				cout<<num[j]<<endl;
			break;
		}
		mod[sum[i]%n]=i;//将取余的数保存起来
	}
	return 0;
}
