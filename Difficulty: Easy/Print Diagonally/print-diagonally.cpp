class Solution {
public:
    int dp[1]; 
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        if (n == 0) return {};
        
        vector<int> res;
        for (int k = 0; k <= 2 * n - 2; ++k) {
            for (int i = 0; i <= k; ++i) {
                int j = k - i;
                if (i < n && j < n) {
                    res.push_back(mat[i][j]);
                }
            }
        }
        return res;
    }
};