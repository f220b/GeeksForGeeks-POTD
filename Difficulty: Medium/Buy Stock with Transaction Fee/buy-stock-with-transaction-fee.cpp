long long dp[1000001][2];

class Solution {
public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return 0;

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }

        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            dp[i][1] = max(-arr[i] + dp[i + 1][0], dp[i + 1][1]);
            dp[i][0] = max(arr[i] - k + dp[i + 1][1], dp[i + 1][0]);
        }

        return (int)dp[0][1];
    }
};