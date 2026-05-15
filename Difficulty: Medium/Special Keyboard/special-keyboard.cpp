class Solution {
public:
    vector<int> dp;
    
    int optimalKeys(int n) {
        if (n <= 6) {
            return n;
        }
        
        dp.assign(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            if (i <= 6) {
                dp[i] = i;
            } else {
                for (int j = 1; j <= i - 3; ++j) {
                    dp[i] = std::max(dp[i], dp[j] * (i - j - 1));
                }
            }
        }
        
        return dp[n];
    }
};