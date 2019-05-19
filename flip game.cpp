#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
#define INF 2147483647
#define cls(x) memset(x,0,sizeof(x))
#define rise(i,a,b) for(int i = a ; i <= b ; i++)
using namespace std;
const double eps(1e-8);
typedef long long lint;

int Map[6][6] = {  };
int flag = 0, step;
int change_row[] = {0,-1,0,1,0};
int change_col[] = {0,0,1,0,-1};

bool all_color(){
	for(int i = 1 ; i <= 4 ; i++)
		for(int j = 1 ; j <= 4 ; j++)
			if(Map[i][j] != Map[1][1]) return false;
	return true;
}

void flip(int row , int col){
	for(int i = 0 ; i < 5 ; i++)
		Map[row+change_row[i]][col+change_col[i]] = !Map[row+change_row[i]][col+change_col[i]];
}

void dfs(int row , int col , int deep){
	if(deep == step){
		flag = all_color();
		return ;
	}
	if(flag) return;
	if(row > 4 || col > 4) return;
	flip(row,col);
	if(row < 4)
		dfs(row+1 , col , deep+1);
	else
		dfs(1, col+1 , deep+1);
	flip(row,col);
	if(row < 4)
		dfs(row+1 , col , deep);
	else
		dfs(1 , col+1 , deep);
	return;
}
void input(){
	for(int i = 1 ; i <= 4 ; i++)
		for(int j = 1 ; j <= 4 ; j++){
			char c;
			cin >> c;
			Map[i][j] = (c == 'b')? 1:0;
		}
}
void solve(){
	for(step = 0 ; step <= 16 ; step++){
		dfs(1,1,0);
		if(flag) break;
	}
	if(flag)
		cout << step << endl;
	else
		cout << "Impossible" << endl;
}
int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w+",stdout);
	input();
	solve();
	return 0;
}