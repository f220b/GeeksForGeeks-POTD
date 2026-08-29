class Solution:
    def countSubsequences(self, s, n):
        MOD = 10**9 + 7
        dp = [0] * n          # dp[r] = count of subsequences with value % n == r
    
        for ch in s:
            d = int(ch)
            ndp = dp[:]       # subsequences that skip this digit
            for r in range(n):
                if dp[r]:
                    nr = (r * 10 + d) % n
                    ndp[nr] = (ndp[nr] + dp[r]) % MOD
            ndp[d % n] = (ndp[d % n] + 1) % MOD   # digit alone
            dp = ndp
    
        return dp[0] % MOD