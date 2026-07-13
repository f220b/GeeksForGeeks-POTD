class Solution {
	public:
	using ll = long long;
	using vi = vector<int>;
	static const int MOD = 1000000007;
	
	ll modPow(int x, int y) {
		ll res = 1;
		
		while (y) {
			if (y & 1)
				res = (res * x) % MOD;
			
			x = (1LL * x * x) % MOD;
			y>>= 1;
		}
		
		return res;
	}
	
	int minOperations(vi &b) {
		int n = b.size();
		
		vector<bool> vis(n, false);
		vi cycles;
		
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				int len = 0;
				int cur = i;
				
				while (!vis[cur]) {
					vis[cur] = true;
					cur = b[cur] - 1;
					len++;
				}
				
				cycles.push_back(len);
			}
		}
		
		vi spf(n + 1);
		for (int i = 0; i <= n; i++)
			spf[i] = i;
		
		for (int i = 2; i * i <= n; i++) {
			if (spf[i] == i) {
				for (int j = i * i; j <= n; j += i) {
					if (spf[j] == j)
						spf[j] = i;
				}
			}
		}
		
		unordered_map<int, int> maxPower;
		for (int len : cycles) {
			unordered_map<int, int> freq;
			
			while (len > 1) {
				int p = spf[len];
				int cnt = 0;
				
				while (len % p == 0) {
					len /= p;
					cnt++;
				}
				
				freq[p] = cnt;
			}
			
			for (auto &it : freq) {
				maxPower[it.first] =
				max(maxPower[it.first], it.second);
			}
		}
		
		ll res = 1;
		for (auto &it : maxPower)
			res = (res * modPow(it.first, it.second)) % MOD;
		return (int)res;
	}
};
