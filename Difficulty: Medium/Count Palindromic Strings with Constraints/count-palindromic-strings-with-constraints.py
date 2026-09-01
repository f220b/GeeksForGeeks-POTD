class Solution:
    def palindromicStrings(self, n: int, k: int) -> int:
        MOD = 10**9 + 7
        ans = 0
    
        for length in range(1, n + 1):
            m = (length + 1) // 2
    
            # Since no character can appear > 2 times, each character chosen 
            # in the first half must be distinct.
            if m > k:
                continue
    
            ways = 1
            for i in range(m):
                ways = (ways * (k - i)) % MOD
    
            ans = (ans + ways) % MOD
    
        return ans