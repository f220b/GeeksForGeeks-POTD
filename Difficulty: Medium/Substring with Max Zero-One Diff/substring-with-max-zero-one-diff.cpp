class Solution {
	public:
	int maxSubstring(string &s) {
		int max_so_far = -1e9;
		int curr_max = 0;
		
		for (char c : s) {
			int val = (c == '0') ? 1 : -1;
			
			curr_max = max(val, curr_max + val);
			max_so_far = max(max_so_far, curr_max);
		}
		return max_so_far;
	}
};
