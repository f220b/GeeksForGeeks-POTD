class Solution {
	public:
	int findCoverage(vector<vector<int>> & mat) {
		int n = mat.size();
		int m = mat[0].size();
		int total = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 0) {
					bool left = false, right = false, up = false, down = false;
					
					for (int k = j - 1; k >= 0; k--) {
						if (mat[i][k] == 1) {
							left = true;
							break;
						}
					}
					
					for (int k = j + 1; k < m; k++) {
						if (mat[i][k] == 1) {
							right = true;
							break;
						}
					}
					
					for (int k = i - 1; k >= 0; k--) {
						if (mat[k][j] == 1) {
							up = true;
							break;
						}
					}
					
					for (int k = i + 1; k < n; k++) {
						if (mat[k][j] == 1) {
							down = true;
							break;
						}
					}
					
					total += (left + right + up + down);
				}
			}
		}
		return total;
	}
};
