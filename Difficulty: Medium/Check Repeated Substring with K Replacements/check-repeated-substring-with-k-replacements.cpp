class Solution {
	public:
	bool kSubstr(string &s, int k) {
		int n = s.size();
		if (n % k != 0)
			return false;
		
		string sub1 = s.substr(0, k);
		string sub2 = "";
		int cnt1 = 1;
		int cnt2 = 0;
		
		for (int i = k; i < n; i += k) {
			if (s.compare(i, k, sub1) == 0)
				cnt1++;
			else {
				if (sub2.empty()) {
					sub2 = s.substr(i, k);
					cnt2++;
				} else if (s.compare(i, k, sub2) == 0)
				cnt2++;
				else
					return false;
			}
		}
		return cnt2 == 0 || cnt1 == 1 || cnt2 == 1;
	}
};
