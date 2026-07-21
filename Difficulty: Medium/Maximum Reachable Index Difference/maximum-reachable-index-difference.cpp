class Solution {
	public:
	vector<int> minStart;
	int maxIndexDifference(string &s) {
		minStart.assign(26, 1e9);
		int maxDiff = -1;
		int n = s.length();
		
		for (int i = 0; i < n; i++) {
			int c = s[i] - 'a';
			if (c == 0) {
				minStart[0] = min(minStart[0], i);
				maxDiff = max(maxDiff, 0);
			} else {
				if (minStart[c - 1] != 1e9) {
					minStart[c] = min(minStart[c], minStart[c - 1]);
					maxDiff = max(maxDiff, i - minStart[c]);
				}
			}
		}
		
		return maxDiff;
	}
};
