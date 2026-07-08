class Solution {
	public:
	using vi = vector<int>;
	using vvi = vector<vi>;
	using pi = pair<int, int>;
	int n, m;
	
	bool isValid(int i, int j) {
		return i >= 0 && j >= 0 && i<n && j<m;
	}
	void bfs(vvi& mat, queue<pi>& x, vvi& visited) {
		vi di = {0, 1, 0, -1};
		vi dj = {1, 0, -1, 0};
		while (!x.empty()) {
			auto [i, j] = x.front();
			x.pop();
			
			for (int k = 0; k < 4; k++) {
				int ni = i + di[k];
				int nj = j + dj[k];
				if (isValid(ni, nj) && !visited[ni][nj] && mat[ni][nj] >= mat[i][j]) {
					x.push({ni, nj});
					visited[ni][nj] = 1;
				}
			}
		}
	}
	int countCoordinates(vector<vector<int>> & mat) {
		// code here
		n = mat.size();
		m = mat[0].size();
		
		vvi reachP(n, vi(m, 0));
		vvi reachQ(n, vi(m, 0));
		
		queue<pi> p;
		queue<pi> q;
		for (int i = 0; i < n; i++) {
			p.push({i, 0});
			reachP[i][0] = 1;
			
			q.push({i, m - 1});
			reachQ[i][m - 1] = 1;
		}
		for (int j = 0; j < m; j++) {
			p.push({0, j});
			reachP[0][j] = 1;
			
			q.push({n - 1, j});
			reachQ[n - 1][j] = 1;
		}
		
		bfs(mat, p, reachP);
		bfs(mat, q, reachQ);
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (reachP[i][j] && reachQ[i][j])
					cnt++;
			}
		}
		return cnt;
	}
};
