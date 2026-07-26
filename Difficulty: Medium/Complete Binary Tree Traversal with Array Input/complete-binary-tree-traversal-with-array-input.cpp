class Solution {
	public:
	using vi = vector<int>;
	vector<vi> dp;
	vector<vi> levelSort(vi& arr) {
		int n = arr.size();
		if (n == 0)
			return {};
		
		dp.clear();
		int idx = 0;
		int levelSize = 1;
		
		while (idx < n) {
			int take = min(levelSize, n - idx);
			vi levelNodes(arr.begin() + idx, arr.begin() + idx + take);
			sort(levelNodes.begin(), levelNodes.end());
			dp.push_back(levelNodes);
			idx += take;
			levelSize *= 2;
		}
		
		return dp;
	}
};
