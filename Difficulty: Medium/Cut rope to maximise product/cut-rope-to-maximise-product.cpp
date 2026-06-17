class Solution {
	public:
	vector<vector<int>> dp;
	int helper(int idx, int n, int lastCut) {
		if (idx == n) {
			if (lastCut == 0)
				return INT_MIN;
			return (n - lastCut);
		}
		if (dp[idx][lastCut] != -1)
			return dp[idx][lastCut];
		
		int cut = (idx - lastCut) * helper(idx + 1, n, idx);
		int notCut = helper(idx + 1, n, lastCut);
		return dp[idx][lastCut] = max(cut, notCut);
	}
	int maxProduct(int n) {
		// code here
		dp.assign(n, vector<int>(n, -1));
		return helper(1, n, 0);
	}
};
