class Solution {
	public:
	int countPairs(vector<int>& arr, int k) {
		int left = 0, right = 0, n = arr.size();
		sort(arr.begin(), arr.end());
		int total = 0;
		while (right < n) {
			while (arr[right] - arr[left] >= k)
				left++;
			total += (right-left);
			right++;
		}
		return total;
	}
};
