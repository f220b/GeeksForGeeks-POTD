class Solution {
	public:
	int maxArea(vector<int>& height) {
		int l = 0;
		int r = height.size() - 1;
		int ans = 0;
		
		while (l < r) {
			int w = r - l - 1;
			int currArea = min(height[l], height[r]) * w;
			ans = max(ans, currArea);
			
			if (height[l] < height[r])
				l++;
			else
				r--;
		}
		
		return ans;
	}
};
