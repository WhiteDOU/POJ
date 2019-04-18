class Solution
{
public:
	int n, m;

	int dfs(vector<vector<int>> &grid, int i, int j)
	{
		int ans = 0;
		if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
			return 1;
		else if (grid[i][j] == 1)
		{
			grid[i][j] = -1;
			int ans = dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
			return ans;
		} else
			return 0;
	}

	int islandPerimeter(vector<vector<int>> &grid)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		n = grid.size();
		m = grid[0].size();
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] ==1)
					ans += dfs(grid,i,j);
			}
		}
		return ans;
	}
};