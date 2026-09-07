class Solution {
    int dp[1005][1005];

    int solve(int i, int inc, int dec, vector<int>& arr) {
        if (i == arr.size()) return 0;
        if (dp[inc + 1][dec + 1] != -1) return dp[inc + 1][dec + 1];

        int ans = 1 + solve(i + 1, inc, dec, arr);

        if (inc == -1 || arr[i] > arr[inc]) {
            ans = min(ans, solve(i + 1, i, dec, arr));
        }

        if (dec == -1 || arr[i] < arr[dec]) {
            ans = min(ans, solve(i + 1, inc, i, arr));
        }

        return dp[inc + 1][dec + 1] = ans;
    }

public:
    int minCount(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(0, -1, -1, arr);
    }
};