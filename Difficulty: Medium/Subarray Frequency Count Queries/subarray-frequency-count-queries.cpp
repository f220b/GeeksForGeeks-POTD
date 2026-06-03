class Solution {
	public:
	vector<int> freqInRange(vector<int>& arr, vector<vector<int>> & queries) {
		// code here
		unordered_map<int, vector<int>> mpp;
		for (int i = 0; i < arr.size(); i++)
			mpp[arr[i]].push_back(i);
		
		vector<int> ans;
		for (int i = 0; i < queries.size(); i++) {
			int l = queries[i][0], r = queries[i][1], x = queries[i][2];
			
			if (!mpp.count(x)) {
				ans.push_back(0);
				continue;
			}
			int left = lower_bound(mpp[x].begin(), mpp[x].end(), l) - mpp[x].begin();
			int right = upper_bound(mpp[x].begin(), mpp[x].end(), r) - mpp[x].begin();
			ans.push_back(right - left);
		}
		return ans;
	}
};
