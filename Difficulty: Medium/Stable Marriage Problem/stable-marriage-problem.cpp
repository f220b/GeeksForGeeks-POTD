#include <vector>
#include <queue>

using namespace std;

int rank_matrix[1001][1001];

class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rank_matrix[i][women[i][j]] = j;
            }
        }

        vector<int> woman_partner(n, -1);
        vector<int> man_partner(n, -1);
        vector<int> next_proposal(n, 0);
        queue<int> free_men;

        for (int i = 0; i < n; ++i) {
            free_men.push(i);
        }

        while (!free_men.empty()) {
            int m = free_men.front();
            free_men.pop();

            int w = men[m][next_proposal[m]++];

            if (woman_partner[w] == -1) {
                woman_partner[w] = m;
                man_partner[m] = w;
            } else {
                int current_m = woman_partner[w];
                if (rank_matrix[w][m] < rank_matrix[w][current_m]) {
                    woman_partner[w] = m;
                    man_partner[m] = w;
                    man_partner[current_m] = -1;
                    free_men.push(current_m);
                } else {
                    free_men.push(m);
                }
            }
        }

        return man_partner;
    }
};