class Solution {
  public:
    using ll = long long;
    
    int numOfWays(int n, int m) {
        ll totalSquares = (ll)n * m;
        ll totalWays = totalSquares * (totalSquares - 1);
        
        ll attackingWays = 0;
        if (n >= 2 && m >= 3) 
            attackingWays += 4LL * (n - 1) * (m - 2);
        if (n >= 3 && m >= 2) 
            attackingWays += 4LL * (n - 2) * (m - 1);
        
        return totalWays - attackingWays;
    }
};