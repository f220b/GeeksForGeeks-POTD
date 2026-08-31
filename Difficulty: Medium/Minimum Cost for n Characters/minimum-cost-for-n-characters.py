class Solution:
    def minCost(self, n: int, i: int, d: int, c: int) -> int:
        if n <= 0:
            return 0
    
        dp = [0] * (n + 1)
    
        for k in range(1, n + 1):
            # Option 1: insert one character
            dp[k] = dp[k - 1] + i
    
            if k % 2 == 0:
                # Option 2: copy-paste from k/2
                dp[k] = min(dp[k], dp[k // 2] + c)
            else:
                # Option 3: copy-paste from (k+1)/2, then delete one
                dp[k] = min(dp[k], dp[(k + 1) // 2] + c + d)
    
        return dp[n]