class Solution {
	public:
	string chooseSwap(string &s) {
		// code here
		int n = s.length();
		vector<int> first(26, -1);
		for (int i = 0; i < n; i++) {
			if (first[s[i] - 'a'] == -1)
				first[s[i]-'a'] = i;
		}
		
		for (int i = 0; i < n; i++) {
			int curr = s[i]-'a';
			
			for (char j = 0; j < curr; j++) {
				if (first[j] > i) {
					char c1 = j + 'a';
					char c2 = s[i];
					
					for (char &ch : s) {
						if (ch == c1)
							ch = c2;
						else if (ch == c2)
							ch = c1;
					}
					return s;
				}
			}
		}
		return s;
	}
};
