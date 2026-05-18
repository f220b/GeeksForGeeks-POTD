class Solution {
    vector<int> dp;
    
    int getSum(int n) {
        if (n == 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = max(n, getSum(n / 2) + getSum(n / 3) + getSum(n / 4));
    }
    
public:
    int maxSum(int n) {
        dp.assign(n + 1, -1);
        return getSum(n);
    }
};