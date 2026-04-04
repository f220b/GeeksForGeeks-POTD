class Solution {
public:
    vector<string> graycode(int n) {
        if (n <= 0) return {"0"};
        
        vector<string> res;
        res.push_back("0");
        res.push_back("1");

        for (int i = 2; i <= n; i++) {
            int sz = res.size();
            for (int j = sz - 1; j >= 0; j--) {
                res.push_back(res[j]);
            }
            for (int j = 0; j < sz; j++) {
                res[j] = "0" + res[j];
            }
            for (int j = sz; j < 2 * sz; j++) {
                res[j] = "1" + res[j];
            }
        }
        return res;
    }
};