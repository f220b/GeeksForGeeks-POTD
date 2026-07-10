class Solution {
	public:
	int getCount(int n) {
		int count = 0;
		for (int k = 2; ((k * (k - 1))>> 1) < n; ++k) {
			int rem = n - ((k * (k - 1))>> 1);
			if (rem % k == 0) 
				count++;
		}
		return count;
	}
};
