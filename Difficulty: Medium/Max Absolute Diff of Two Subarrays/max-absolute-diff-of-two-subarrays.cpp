class Solution {
	public:
	using vi = vector<int>;
	int maxDiffSubArrays(vector<int>& arr) {
		int n = arr.size();
		if (n < 2)
			return 0;
		
		vi max_left(n), min_left(n);
		vi max_right(n), min_right(n);
		
		int max_so_far = arr[0], curr_max = arr[0];
		int min_so_far = arr[0], curr_min = arr[0];
		max_left[0] = max_so_far;
		min_left[0] = min_so_far;
		
		for (int i = 1; i < n; i++) {
			curr_max = max(arr[i], curr_max + arr[i]);
			max_so_far = max(max_so_far, curr_max);
			max_left[i] = max_so_far;
			
			curr_min = min(arr[i], curr_min + arr[i]);
			min_so_far = min(min_so_far, curr_min);
			min_left[i] = min_so_far;
		}
		
		max_so_far = arr[n - 1];
		curr_max = arr[n - 1];
		min_so_far = arr[n - 1];
		curr_min = arr[n - 1];
		max_right[n - 1] = max_so_far;
		min_right[n - 1] = min_so_far;
		
		for (int i = n - 2; i >= 0; i--) {
			curr_max = max(arr[i], curr_max + arr[i]);
			max_so_far = max(max_so_far, curr_max);
			max_right[i] = max_so_far;
			
			curr_min = min(arr[i], curr_min + arr[i]);
			min_so_far = min(min_so_far, curr_min);
			min_right[i] = min_so_far;
		}
		
		int max_diff = 0;
		for (int i = 0; i < n - 1; i++) {
			int diff1 = abs(max_left[i] - min_right[i + 1]);
			int diff2 = abs(max_right[i + 1] - min_left[i]);
			max_diff = max({max_diff, diff1, diff2});
		}
		
		return max_diff;
	}
};
