#include <vector>

using namespace std;

class Solution {
    int dp[205][205][205];
    int dpSumR[205][205][205];
    int dpSumC[205][205][205];
    int suf[205][205];
    int next_r[205][205];
    int next_c[205][205];
    int m, n;
    const int MOD = 1e9 + 7;

    int get_dp(int r, int c, int k) {
        if (suf[r][c] == 0) {
            return 0;
        }
        if (k == 1) {
            return 1;
        }
        if (dp[r][c][k] != -1) {
            return dp[r][c][k];
        }

        int R = next_r[r][c];
        int C = next_c[r][c];
        long long ans = 0;

        if (R != -1) {
            ans = (ans + get_sum_r(R, c, k - 1)) % MOD;
        }
        if (C != -1) {
            ans = (ans + get_sum_c(r, C, k - 1)) % MOD;
        }

        return dp[r][c][k] = ans;
    }

    int get_sum_r(int r, int c, int k) {
        if (r >= m) {
            return 0;
        }
        if (dpSumR[r][c][k] != -1) {
            return dpSumR[r][c][k];
        }
        return dpSumR[r][c][k] = (get_dp(r, c, k) + get_sum_r(r + 1, c, k)) % MOD;
    }

    int get_sum_c(int r, int c, int k) {
        if (c >= n) {
            return 0;
        }
        if (dpSumC[r][c][k] != -1) {
            return dpSumC[r][c][k];
        }
        return dpSumC[r][c][k] = (get_dp(r, c, k) + get_sum_c(r, c + 1, k)) % MOD;
    }

public:
    using vi = vector<int>;

    int findWays(vector<vi>& matrix, int k) {
        m = matrix.size();
        n = matrix[0].size();

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                suf[i][j] = 0;
                for (int l = 0; l <= k; ++l) {
                    dp[i][j][l] = -1;
                    dpSumR[i][j][l] = -1;
                    dpSumC[i][j][l] = -1;
                }
            }
        }

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                suf[i][j] = matrix[i][j] + suf[i + 1][j] + suf[i][j + 1] - suf[i + 1][j + 1];
            }
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                next_r[r][c] = -1;
                for (int nr = r + 1; nr < m; ++nr) {
                    if (suf[r][c] > suf[nr][c]) {
                        next_r[r][c] = nr;
                        break;
                    }
                }
                
                next_c[r][c] = -1;
                for (int nc = c + 1; nc < n; ++nc) {
                    if (suf[r][c] > suf[r][nc]) {
                        next_c[r][c] = nc;
                        break;
                    }
                }
            }
        }

        return get_dp(0, 0, k);
    }
};