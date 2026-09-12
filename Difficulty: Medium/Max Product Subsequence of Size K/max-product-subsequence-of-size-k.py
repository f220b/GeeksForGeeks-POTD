class Solution:
    def maxProduct(self, arr: list[int], k: int) -> int:
        n = len(arr)
        # dp[i][j] = (max_product, min_product) using exactly j elements from arr[:i]
        dp = [[None] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = (1, 1)

        for i in range(1, n + 1):
            dp[i][0] = (1, 1)
            hi = min(i, k)
            for j in range(1, hi + 1):
                cand_max = []
                cand_min = []

                # Option 1: skip arr[i-1]
                if dp[i - 1][j] is not None:
                    mx, mn = dp[i - 1][j]
                    cand_max.append(mx)
                    cand_min.append(mn)

                # Option 2: take arr[i-1]
                if dp[i - 1][j - 1] is not None:
                    pmx, pmn = dp[i - 1][j - 1]
                    v1 = pmx * arr[i - 1]
                    v2 = pmn * arr[i - 1]
                    cand_max.extend([v1, v2])
                    cand_min.extend([v1, v2])

                if cand_max:
                    dp[i][j] = (max(cand_max), min(cand_min))

        return dp[n][k][0]