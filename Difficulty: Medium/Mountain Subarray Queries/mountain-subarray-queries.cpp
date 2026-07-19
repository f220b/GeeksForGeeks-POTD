class Solution {
	public:
	using vi = vector<int>;
	vector<bool> processQueries(vi &arr, vector<vi> &queries) {
		int n = arr.size();
		
		vi inc(n);
		inc[n - 1] = n - 1;
		vi dec(n);
		dec[n - 1] = n - 1;
		
		for (int i = n - 2; i >= 0; i--) {
			if (arr[i + 1] <= arr[i])
				dec[i] = dec[i + 1];
			else
				dec[i] = i;
			
			if (arr[i + 1] >= arr[i])
				inc[i] = inc[i + 1];
			else
				inc[i] = i;
		}
		vector<bool> ans;
		for (auto q : queries) {
		    int l = q[0], r = q[1];
			int top = inc[l];
			int bottom = dec[top];
			if (bottom >= r)
				ans.push_back(true);
			else
				ans.push_back(false);
		}
		return ans;
	}
};
