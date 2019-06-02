#include <iostream>

using namespace std;


#define MAX_w 20
#define MAX_h 20

int w, h;
int step = 0;
int minStep;
int srow, scol;

int maze[MAX_w][MAX_h];

const int go[][2] = {
		0, -1,
		1, 0,
		0, 1,
		-1, 0
};


void dfs(int row, int col, int step)
{
	if (step >= 10 || step > minStep)
		return;
	for (int d = 0; d < 4; ++d)
	{
		int rnew = row;
		int cnew = col;
		while (rnew >= 0 && rnew < h && cnew>=0 && cnew < w)
		{
			switch(maze[rnew][cnew])
			{
				case 0:
					rnew += go[d][0];
					cnew += go[d][1];
					break;
				case 3:
					if (step + 1 < minStep)
					{
						minStep = step + 1;
					}
					rnew = -1;
					break;
				case 1:
					if (!(rnew-go[d][0]==row && cnew-go[d][1]==col))
					{
						maze[rnew][cnew] = 0;
						dfs(rnew-go[d][0],cnew-go[d][1],step+1);
						maze[rnew][cnew] = 1;
					}
					rnew = -1;
					break;
				default:
					break;
			}
		}
	}
}
int main()
{
	while (cin >> w >> h, w > 0) {
		// 输入
		for (int row = 0; row < h; ++row) {
			for (int col = 0; col < w; ++col) {
				cin >> maze[row][col];
			}
		}
		// 为2的点为起始点
		for (int row = 0; row < h; ++row) {
			for (int col = 0; col < w; ++col) {
				if (maze[row][col] == 2) {
					srow = row;
					scol = col;
					break;
				}
			}
		}
		maze[srow][scol] = 0;
		minStep = 11;
		dfs(srow, scol, 0);
		if (minStep > 10) {
			minStep = -1;
		}
		// 输出结果
		cout << minStep << endl;
	}
	
}