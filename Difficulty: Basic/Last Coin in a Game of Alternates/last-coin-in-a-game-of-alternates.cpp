class Solution {
	public:
	int coin(vector<int>& arr) {
		// code here
		int ans = INT_MAX;
		for (int i : arr)
			ans = min(ans, i);
		
		return ans;
	}
};
