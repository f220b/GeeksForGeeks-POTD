class Solution {
	public:
	int sumDiffPairs(vector<int>& arr, int k) {
		sort(arr.rbegin(), arr.rend());
		int n = arr.size();
		int res = 0;
		
		for (int i = 0; i < n - 1;) {
			if (arr[i] - arr[i + 1] < k) {
				res += arr[i] + arr[i + 1];
				i += 2;
			} else 
				i++;
		}
		return res;
	}
};
