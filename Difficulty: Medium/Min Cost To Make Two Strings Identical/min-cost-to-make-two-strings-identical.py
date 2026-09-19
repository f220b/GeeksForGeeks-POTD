class Solution:
    def findMinCost(self, s1: str, s2: str, costS1: int, costS2: int) -> int:
        n1, n2 = len(s1), len(s2)
        dp = [[-1] * n2 for _ in range(n1)]

        def lcs(i, j):
            if i == n1 or j == n2:
                return 0
            if dp[i][j] != -1:
                return dp[i][j]
                
            len = 0
            if s1[i] == s2[j]:
                len = 1 + lcs(i + 1, j + 1)
            else:
                len = max(lcs(i, j + 1), lcs(i + 1, j))

            dp[i][j] = len
            return len

        length = lcs(0, 0)
        return ((n1 - length) * costS1) + ((n2 - length) * costS2)
