
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 100005;

struct Node
{
	int address, data, next;
	bool flag;

	bool operator<(const Node &b) const
	{
		if (flag == false || b.flag == false)
			return flag > b.flag;
		else
			return data < b.data;
	}
} node[maxn];

int main()
{
	for (int i = 0; i < maxn; ++i)
	{
		node[i].flag = false;
	}

	int n, begin, address;
	cin >> n >> begin;
	for (int i = 0; i < n; ++i)
	{
		cin >> address;
		cin >> node[address].data >> node[address].next;
		node[address].address = address;
	}
	int count = 0, p = begin;
	while (p != -1)
	{
		node[p].flag = true;
		count++;
		p = node[p].next;
	}

	if (count == 0)
	{
		cout << 0 << -1;
	}
	else
	{
		sort(node,node+maxn);
	}
}
