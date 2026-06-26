class Solution {
	public:
	int n1, n2;
	const int MOD = 1e9 + 7;
	vector<vector<int>> dp;
	
	int helper(int i, int j, string &s1, string &s2) {
		if (j == n2)
			return 1;
		if (i == n1)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		
		int cnt = 0;
		if (s1[i] == s2[j])
			cnt = (cnt + helper(i + 1, j + 1, s1, s2)) % MOD;
		
		cnt = (cnt + helper(i + 1, j, s1, s2)) % MOD;
		return dp[i][j] = cnt;
	}
	int countWays(string &s1, string &s2) {
		n1 = s1.length();
		n2 = s2.length();
		dp.assign(n1, vector<int>(n2, -1));
		return helper(0, 0, s1, s2);
	}
};
