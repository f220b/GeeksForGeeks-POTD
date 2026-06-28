int dp[1001][1001][2];

class Solution {
  public:
    int countStrings(int n, int k) {
        if (k >= n) return 0;
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }
        
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;
        
        int mod = 1e9 + 7;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % mod;
                
                dp[i][j][1] = dp[i-1][j][0];
                if (j > 0) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-1][1]) % mod;
                }
            }
        }
        
        return (dp[n][k][0] + dp[n][k][1]) % mod;
    }
};