class Solution {
public:
    int countSpanTree(int n, vector<vector<int>>& edges) {
        if (n <= 1) return 1;
        vector<vector<long long>> L(n - 1, vector<long long>(n - 1, 0));
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (u < n - 1 && v < n - 1) {
                L[u][v]--;
                L[v][u]--;
                L[u][u]++;
                L[v][v]++;
            } else if (u == n - 1) {
                L[v][v]++;
            } else if (v == n - 1) {
                L[u][u]++;
            }
        }
        long long res = 1;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                while (L[j][i] != 0) {
                    long long t = L[i][i] / L[j][i];
                    for (int k = i; k < n - 1; ++k) {
                        L[i][k] -= t * L[j][k];
                    }
                    swap(L[i], L[j]);
                    res = -res;
                }
            }
            if (L[i][i] == 0) return 0;
            res *= L[i][i];
        }
        if (res < 0) return -res;
        return res;
    }
};