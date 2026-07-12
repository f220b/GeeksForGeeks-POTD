class Solution {
	public:
	using ll = long long;
	int maxAmount(vector<int>& arr, int k) {
		ll low = 0, high = 0;
		for (int x : arr) {
			if (x > high)
				high = x;
		}
		
		ll targetPrice = 0;
		while (low <= high) {
			ll mid = low + ((high - low)>> 1);
			ll count = 0;
			for (int x : arr) {
				if (x >= mid)
					count += (x - mid + 1);
			}
			if (count >= k) {
				targetPrice = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		
		ll totalEarned = 0;
		ll ticketsSold = 0;
		ll mod = 1e9 + 7;
		
		for (int x : arr) {
			if (x > targetPrice) {
				ll count = x - targetPrice;
				ticketsSold += count;
				ll sum = (x + targetPrice + 1) * count / 2;
				totalEarned = (totalEarned + sum) % mod;
			}
		}
		
		ll remaining = k - ticketsSold;
		if (remaining > 0)
			totalEarned = (totalEarned + remaining * targetPrice) % mod;
		
		return totalEarned;
	}
};
