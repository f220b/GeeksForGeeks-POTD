int dp[1005][1005][2];

class Solution {
public:
    int n;
    using vi = vector<int>;
    
    bool helper(int i, int rem, bool started, vi& arr, int k) {
        if (started && rem == 0)
            return true;
        if (i == n)
            return false;
        
        if (dp[i][rem][started] != -1)
            return dp[i][rem][started];
        bool pick = helper(i + 1, (rem + arr[i]) % k, true, arr, k);
        bool notPick = helper(i + 1, rem, started, arr, k);
        return dp[i][rem][started] = (pick || notPick);
    }

    bool divisibleByK(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, false, arr, k);
    }
};