class Solution {
	public:
	bool wifiRange(string &s, int x) {
		int n = s.length();
		int maxCovered = -1;
		
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				if (i - x > maxCovered + 1)
					return false;
				maxCovered = i + x;
			}
		}
		return maxCovered >= n - 1;
	}
};
