class Solution {
public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int r = 0, c = 0;
        int dir = 0;
        int prev_r = 0, prev_c = 0;
        
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        
        while (r >= 0 && r < n && c >= 0 && c < m) {
            prev_r = r;
            prev_c = c;
            
            if (mat[r][c] == 1) {
                dir = (dir + 1) % 4;
                mat[r][c] = 0;
            }
            
            r += dr[dir];
            c += dc[dir];
        }
        
        return {prev_r, prev_c};
    }
};