#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
bool chessBoard[30][30];
bool flag;
struct Path
{
	int x, y;

} path[30];
int n, m;
int go[][2] = {
		-2, -1, -2, 1, -1, -2, -1, 2, 1, -2, 1, 2, 2, -1, 2, 1
};

void dfs(int x,int y,int step)
{

	if (flag)
		return;
	path[step].x = x;
	path[step].y = y;
	if (step == n* m )
	{
		flag = true;
		return;
	}
	for (int i = 0; i < 8; ++i)
	{
		int xnew = x + go[i][0];
		int ynew = y + go[i][1];
		if (xnew>=1 && xnew<=n&&ynew >=1 && ynew<=m&&chessBoard[xnew][ynew]== false)
		{
			chessBoard[xnew][ynew] = true;
			dfs(xnew,ynew,step+1);
			chessBoard[xnew][ynew] = false;
		}
	}
	return;

}


int main()
{
	ios::sync_with_stdio(false);
//    int t;
//    cin >> t;
//    while (n--)
//    {
//
//        cin >> m >> n;
//
//        int now = 1;
//        for (int i = 0; i < 27; ++i)
//        {
//            for (int j = 0; j < 27; ++j)
//            {
//                chessBoard[i][j] = false;
//            }
//        }
//        flag = false;
//        memset(path, 0, sizeof(path));
//        chessBoard[1][1] = true;
//        dfs(1, 1, 1);
//        if (flag)
//        {
//            for (int i = 1; i <= n * m; ++i)
//            {
//                cout << char(path[i].x - 1 + 'A') << int(path[i].y);
//            }
//            cout << endl;
//        } else
//            cout << "impossible\n";
//
//    }
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d%d", &m,&n); //先输入列再输入行

		memset(chessBoard,0,sizeof(chessBoard));
		memset(path,0,sizeof(path));
		flag = 0;
		chessBoard[1][1] = 1;
		dfs(1,1,1);

		printf("Scenario #%d:\n", t);
		if(flag)
		{
			for(int i = 1; i <= n*m; i++)
				printf("%c%d", path[i].x-1+'A', path[i].y);
			printf("\n");
		}
		else printf("impossible\n");

		if(t != T) printf("\n");
	}

  

}
