class Solution {
public:
    int findSmallest(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long long res = 1;
        
        for (int x : arr) {
            if (x > res) {
                break;
            }
            res += x;
        }
        
        return res;
    }
};