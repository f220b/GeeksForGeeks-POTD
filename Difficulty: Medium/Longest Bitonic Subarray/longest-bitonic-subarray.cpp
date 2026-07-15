class Solution {
	public:
	using vi = vector<int>;
	vi inc_dp;
	vi dec_dp;
	
	int bitonic(vi &arr) {
		int n = arr.size();
		if (n == 0)
			return 0;
		
		inc_dp.assign(n, 1);
		dec_dp.assign(n, 1);
		
		for (int i = 1; i < n; i++) {
			if (arr[i] >= arr[i - 1]) 
				inc_dp[i] = inc_dp[i - 1] + 1;
		}
		
		for (int i = n - 2; i >= 0; i--) {
			if (arr[i] >= arr[i + 1]) 
				dec_dp[i] = dec_dp[i + 1] + 1;
		}
		
		int max_len = 0;
		for (int i = 0; i < n; i++) 
			max_len = max(max_len, inc_dp[i] + dec_dp[i] - 1);
		
		return max_len;
	}
};
