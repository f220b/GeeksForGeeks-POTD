class Solution {
	public:
	int maxSumWithK(vector<int>& arr, int k) {
		int n = arr.size();
		
		// maxSum[i] stores the maximum subarray sum
		// ending at index i
		vector<int> maxSum(n);
		maxSum[0] = arr[0];
		
		// Use Kadane's algorithm to fill maxSum[]
		int currMax = arr[0];
		for (int i = 1; i < n; i++) {
			currMax = max(arr[i], currMax + arr[i]);
			maxSum[i] = currMax;
		}
		
		// Sum of first k elements
		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += arr[i];
		}
		
		// Use sliding window concept
		int res = sum;
		for (int i = k; i < n; i++) {
			
			// Compute sum of k elements ending with a[i]
			sum = sum + arr[i] - arr[i - k];
			
			// Update result if required
			res = max(res, sum);
			
			// Extend the current window with the maximum
			// subarray ending at index i-k
			res = max(res, sum + maxSum[i - k]);
		}
		
		return res;
	}
};
