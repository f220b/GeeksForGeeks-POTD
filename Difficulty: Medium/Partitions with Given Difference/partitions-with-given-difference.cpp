int dp[51][2501];

class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = 0;
        for (int x : arr) totalSum += x;

        if ((totalSum + diff) % 2 != 0 || totalSum < diff) {
            return 0;
        }

        int target = (totalSum + diff) / 2;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = 0;
            }
        }

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= arr[i - 1]) {
                    dp[i][j] += dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};