class Solution {
	public:
	int dp[10][82];
	int helper(int idx, int n, int sum) {
		if (idx == n)
			return sum == 0;
		if (dp[idx][sum] != -1)
			return dp[idx][sum];
		
		int cnt = 0;
		int start = (idx == 0) ? 1 : 0;
		for (int i = start; i <= 9; i++) {
			if (sum >= i)
				cnt += helper(idx + 1, n, sum - i);
		}
		return dp[idx][sum] = cnt;
	}
	
	int countWays(int n, int sum) {
		memset(dp, -1, sizeof(dp));
		int ans = helper(0, n, sum);
		return ans == 0 ? -1 : ans;
	}
};
