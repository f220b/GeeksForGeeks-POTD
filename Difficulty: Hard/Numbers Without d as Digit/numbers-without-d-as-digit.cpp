class Solution {
	public:
	int countWithout(int n, int d) {
		if (n <= 0)
			return 0;
		
		string s = to_string(n);
		int L = s.size();
		int firstChoices = (d == 0) ? 9 : 8; // leading digit: 1..9 minus d
		
		long long pow9[11];
		pow9[0] = 1;
		for (int i = 1; i <= 10; i++)
			pow9[i] = pow9[i - 1] * 9;
		
		long long res = 0;
		for (int k = 1; k < L; k++)
			res += 1LL * firstChoices * pow9[k - 1];
		
		bool full = true; // n itself survives?
		for (int i = 0; i < L; i++) {
			int cur = s[i] - '0';
			int lo = (i == 0) ? 1 : 0; // no leading zero
			for (int dig = lo; dig < cur; dig++)
				if (dig != d)
				res += pow9[L - i - 1];
			
			if (cur == d) { full = false; break; }
		}
		if (full) res += 1; // n has no digit d
		
		return (int)res;
	}
};
