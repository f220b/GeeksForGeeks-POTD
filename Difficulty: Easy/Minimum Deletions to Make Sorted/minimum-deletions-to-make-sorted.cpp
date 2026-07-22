class Solution {
	public:
	int minDeletions(vector<int>& arr) {
		int n = arr.size();
		if (n == 0)
			return 0;
		
		vector<int> lis;
		for (int x : arr) {
			auto it = lower_bound(lis.begin(), lis.end(), x);
			if (it == lis.end())
				lis.push_back(x);
			else
				*it = x;
		}
		
		return n - lis.size();
	}
};
