class Solution {
	public:
	int maxPathSum(vector<int> &a, vector<int> &b) {
		int m = a.size(), n = b.size();
		int i = 0, j = 0;
		int result = 0, sum1 = 0, sum2 = 0;
		
		while (i < m && j < n) {
			if (a[i] < b[j])
				sum1 += a[i++];
			else if (a[i]>b[j])
				sum2 += b[j++];
			else {
				result += max(sum1, sum2) + a[i];
				sum1 = 0;
				sum2 = 0;
				i++;
				j++;
			}
		}
		while (i<m)
			sum1 += a[i++];
		while (j<n)
			sum2 += b[j++];
		result += max(sum1, sum2);
		
		return result;
	}
};
