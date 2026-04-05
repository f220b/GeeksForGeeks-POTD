int dp[21][2001];

class Solution {
public:
    int countSubsets(vector<int>& arr, int sum) {
        int n = arr.size();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (arr[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - arr[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }

    int totalWays(vector<int>& arr, int target) {
        int totalSum = 0;
        for (int x : arr) totalSum += x;

        if (abs(target) > totalSum || (target + totalSum) % 2 != 0 || (target + totalSum) < 0) {
            return 0;
        }

        int s1 = (target + totalSum) / 2;
        return countSubsets(arr, s1);
    }
};