class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> res;
        for (int val : arr) {
            if (!res.empty() && (res.back() >= 0) != (val >= 0)) {
                res.pop_back();
            } else {
                res.push_back(val);
            }
        }
        return res;
    }
};