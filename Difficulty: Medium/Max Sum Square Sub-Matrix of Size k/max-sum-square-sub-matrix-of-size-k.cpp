class Solution {
	public:
	using ll = long long;
	using vl = vector<ll>;
	int maximumSum(vector<vector<int>> & mat, int k) {
		int n = mat.size();
		vector<vl> preSum(n, vl(n, 0));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ll top = (i >= 1) ? preSum[i - 1][j] : 0;
				ll left = (j >= 1) ? preSum[i][j - 1] : 0;
				ll diag = (i >= 1 && j >= 1) ? preSum[i - 1][j - 1] : 0;
				
				preSum[i][j] = (ll)mat[i][j] + top + left - diag;
			}
		}
		ll maxSum = LLONG_MIN;
		for (int i = k - 1; i < n; i++) {
			for (int j = k - 1; j < n; j++) {
				ll top = (i >= k) ? preSum[i - k][j] : 0;
				ll left = (j >= k) ? preSum[i][j - k] : 0;
				ll diag = (i >= k && j >= k) ? preSum[i - k][j - k] : 0;
				ll total = preSum[i][j];
				
				maxSum = max(maxSum, total - top - left + diag);
			}
		}
		return (int)maxSum;
	}
};
