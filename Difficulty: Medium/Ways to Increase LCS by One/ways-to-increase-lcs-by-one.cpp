class Solution {
	public:
	int helper(string &s1, string &s2) {
		int n1 = s1.length();
		int n2 = s2.length();
		
		vector<vector<int>> position(26);
		for (int i = 1; i <= n2; i++)
			position[s2[i - 1] - 'a'].push_back(i);
		
		vector<vector<int>> lcsl(n1 + 2, vector<int>(n2 + 2, 0));
		vector<vector<int>> lcsr(n1 + 2, vector<int>(n2 + 2, 0));
		for (int i = 1; i <= n1; i++) {
			for (int j = 1; j <= n2; j++) {
				if (s1[i - 1] == s2[j - 1])
					lcsl[i][j] = 1 + lcsl[i - 1][j - 1];
				else
					lcsl[i][j] = max(lcsl[i - 1][j], lcsl[i][j - 1]);
			}
		}
		
		for (int i = n1; i >= 1; i--) {
			for (int j = n2; j >= 1; j--) {
				if (s1[i - 1] == s2[j - 1])
					lcsr[i][j] = 1 + lcsr[i + 1][j + 1];
				else
					lcsr[i][j] = max(lcsr[i + 1][j], lcsr[i][j + 1]);
			}
		}
		
		int ways = 0;
		int baseLCS = lcsl[n1][n2];
		for (int i = 0; i <= n1; i++) {
			for (char c = 'a'; c <= 'z'; c++) {
				vector<int> &posList = position[c - 'a'];
				for (int j = 0; j < (int)posList.size(); j++) {
					int p = posList[j];
					
					if (lcsl[i][p - 1] + lcsr[i + 1][p + 1] == baseLCS) {
						ways++;
						break;
					}
				}
			}
		}
		
		return ways;
	}
	int waysToIncreaseLCSBy1(string &s1, string &s2) {
		// code here
		return helper(s1, s2);
	}
};
