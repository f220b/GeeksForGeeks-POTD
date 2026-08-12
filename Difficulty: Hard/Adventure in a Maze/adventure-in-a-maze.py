class Solution:
    def findWays(self, grid):
        n = len(grid)
        MOD = 10**9 + 7

        dp = [[None] * n for _ in range(n)]

        def helper(i, j):
            if dp[i][j] is not None:
                return dp[i][j]
                
            if i == n - 1 and j == n - 1:
                dp[i][j] = (1, grid[i][j])
                return dp[i][j]

            val = grid[i][j]
            ways = 0
            best = -1

            if (val == 1 or val == 3) and j + 1 < n:
                w, a = helper(i, j + 1)
                if w > 0:
                    ways = (ways + w) % MOD
                    best = max(best, a)

            if (val == 2 or val == 3) and i + 1 < n:
                w, a = helper(i + 1, j)
                if w > 0:
                    ways = (ways + w) % MOD
                    best = max(best, a)

            dp[i][j] = (0, -1) if ways == 0 else (ways, best + val)
            return dp[i][j]

        ways, adv = helper(0, 0)
        return [ways, adv if ways > 0 else 0]