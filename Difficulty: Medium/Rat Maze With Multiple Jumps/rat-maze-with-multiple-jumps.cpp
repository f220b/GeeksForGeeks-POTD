class Solution {
    vector<vector<int>> failed;

    bool solve(int r, int c, int n, vector<vector<int>>& mat, vector<vector<int>>& ans) {
        if (r == n - 1 && c == n - 1) {
            ans[r][c] = 1;
            return true;
        }
        
        if (mat[r][c] == 0 || failed[r][c]) {
            return false;
        }
        
        ans[r][c] = 1;
        int maxJump = mat[r][c];
        
        for (int step = 1; step <= maxJump; ++step) {
            if (c + step < n && solve(r, c + step, n, mat, ans)) {
                return true;
            }
            if (r + step < n && solve(r + step, c, n, mat, ans)) {
                return true;
            }
        }
        
        ans[r][c] = 0;
        failed[r][c] = 1;
        return false;
    }

public:
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();
        failed.assign(n, vector<int>(n, 0));
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        if (solve(0, 0, n, mat, ans)) {
            return ans;
        }
        return {{-1}};
    }
};