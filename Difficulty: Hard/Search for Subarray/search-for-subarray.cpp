class Solution {
public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        vector<int> ans;
        
        if (m == 0 || n < m) {
            return ans;
        }

        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        
        while (i < m) {
            if (b[i] == b[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        i = 0;
        int j = 0;
        
        while (i < n) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }
            if (j == m) {
                ans.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && a[i] != b[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return ans;
    }
};