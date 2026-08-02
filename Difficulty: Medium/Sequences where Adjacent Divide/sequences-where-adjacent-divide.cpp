#define pb push_back
class Solution {
	public:
	const int MOD = 1e9 + 7;
	using ll = long long;
	using vi = vector<int>;
	vector<vi> dp;
	int count(int n, int m) {
		vector<vi> adj(m + 1);
		for (int i = 1; i <= m; i++) {
			for (int j = i; j <= m; j += i) {
				adj[i].pb(j);
				if (i != j) 
					adj[j].pb(i);
			}
		}
		
		dp.assign(n + 1, vi(m + 1, 0));
		for (int j = 1; j <= m; j++) 
			dp[1][j] = 1;
		
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ll sum = 0;
				for (int x : adj[j]) 
					sum = (sum + dp[i - 1][x]) % MOD;
				dp[i][j] = sum;
			}
		}
		
		ll ans = 0;
		for (int j = 1; j <= m; j++) 
			ans = (ans + dp[n][j]) % MOD;
		
		return ans;
	}
};
