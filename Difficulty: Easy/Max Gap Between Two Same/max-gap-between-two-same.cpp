class Solution {
	public:
	int maxCharGap(string &s) {
		// code here
		int idx[26];
		memset(idx, -1, sizeof(idx));
		int maxGap = -1;
		
		for (int i = 0; i < s.length(); i++) {
			char ch = s[i];
			if (idx[ch - 'a'] != -1)
				maxGap = max(maxGap, i - idx[ch - 'a']-1);
			else
				idx[ch - 'a'] = i;
		}
		return maxGap;
	}
};
