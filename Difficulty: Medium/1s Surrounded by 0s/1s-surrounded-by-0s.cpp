class Solution {
	public:
	int n, m;
	vector<int> di = {0, 1, 0, -1};
	vector<int> dj = {1, 0, -1, 0};
	
	void dfs(int i, int j, vector<vector<int>> & grid) {
		if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
			return;
		
		grid[i][j] = 0;
		for (int x = 0; x < 4; x++)
			dfs(i + di[x], j + dj[x], grid);
	}
	int cntOnes(vector<vector<int>> & grid) {
		// code here
		if (grid.empty())
			return 0;
		
		n = grid.size();
		m = grid[0].size();
		for (int i = 0; i < n; i++) {
			if (grid[i][0] == 1)
				dfs(i, 0, grid);
			if (grid[i][m - 1] == 1)
				dfs(i, m - 1, grid);
		}
		for (int j = 0; j < m; j++) {
			if (grid[0][j] == 1)
				dfs(0, j, grid);
			if (grid[n - 1][j] == 1)
				dfs(n - 1, j, grid);
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1)
					count++;
			}
		}
		return count;
	}
};
