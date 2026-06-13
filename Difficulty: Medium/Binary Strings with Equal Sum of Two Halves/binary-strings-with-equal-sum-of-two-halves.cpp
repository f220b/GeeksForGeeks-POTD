class Solution {
	public:
	using ll = long long;
	
	ll power(ll base, ll exp, ll mod) {
		ll res = 1;
		base %= mod;
		while (exp > 0) {
			if (exp % 2 == 1) res = (res * base)
				% mod;
			base = (base * base) % mod;
			exp /= 2;
		}
		return res;
	}
	int computeValue(int n) {
		ll mod = 1e9 + 7;
		ll num = 1;
		ll den = 1;
		
		for (int i = 1; i <= n; i++) {
			num = (num * (n + i)) % mod;
			den = (den * i) % mod;
		}
		
		ll ans = (num * power(den, mod - 2, mod)) % mod;
		return ans;
	}
};
