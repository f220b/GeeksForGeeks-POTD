class Solution {
	public:
	int countKdivPairs(vector<int>& arr, int k) {
		// code here
		vector<int> rem(k, 0);
		for (int a : arr)
			rem[a%k]++;
		
		int cnt = 0;
		for (int i = 1; i <= (k>> 1); i++) {
			if (i == (k - i))
				cnt += (rem[i]*(rem[i]-1))>> 1;
			else
				cnt += rem[i]*rem[k - i];
		}
		// nC2 for numbers with num%k==0
		cnt += (rem[0]*(rem[0]-1))>> 1;
		return cnt;
	}
};
