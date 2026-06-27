class Solution {
	public:
	int countWays(int n, int m) {
		const int MOD = 1e9 + 7;
		
		vector<long long> dp(n + 1, 1);
		
		if (n >= m)
			dp[m] = 2;
		
		for (int i = m + 1; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
		}
		
		return dp[n];
	}
};
