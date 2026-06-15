class Solution {
    vector<int> dp;
public:
    int minimumCost(vector<int>& cost, int w) {
        dp.assign(w + 1, 1e9);
        dp[0] = 0;
        
        int n = cost.size();
        for (int i = 0; i < n; ++i) {
            if (cost[i] != -1) {
                int weight = i + 1;
                for (int j = weight; j <= w; ++j) {
                    if (dp[j - weight] != 1e9) {
                        dp[j] = min(dp[j], dp[j - weight] + cost[i]);
                    }
                }
            }
        }
        
        return dp[w] == 1e9 ? -1 : dp[w];
    }
};