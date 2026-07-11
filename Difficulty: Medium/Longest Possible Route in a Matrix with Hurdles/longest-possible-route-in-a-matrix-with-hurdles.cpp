class Solution {
	using vi = vector<int>;
	using vvi = vector<vi>;
	int maxDist;
	int n, m;
	int dr[4] = {-1, 1, 0, 0};
	int dc[4] = {0, 0, -1, 1};
	
	void solve(vvi& mat, int r, int c, int xd, int yd, int dist) {
		if (r == xd && c == yd) {
			maxDist = max(maxDist, dist);
			return;
		}
		
		mat[r][c] = 0;
		
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1) {
				solve(mat, nr, nc, xd, yd, dist + 1);
			}
		}
		
		mat[r][c] = 1;
	}
	
	public:
	int longestPath(vvi& mat, int xs, int ys, int xd, int yd) {
		n = mat.size();
		m = mat[0].size();
		
		if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
			return - 1;
		
		maxDist = -1;
		solve(mat, xs, ys, xd, yd, 0);
		return maxDist;
	}
};
