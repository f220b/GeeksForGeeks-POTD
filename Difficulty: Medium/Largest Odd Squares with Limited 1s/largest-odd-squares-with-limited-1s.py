class Solution:
    def largestSquare(self, mat: list[list[int]], queries: list[list[int]], k: int) -> list[int]:
        n, m = len(mat), len(mat[0])

        # 2D prefix sum: pre[i][j] = sum of mat[0..i-1][0..j-1]
        pre = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(n):
            row_sum = 0
            for j in range(m):
                row_sum += mat[i][j]
                pre[i + 1][j + 1] = pre[i][j + 1] + row_sum

        def count(r1, c1, r2, c2):
            return (pre[r2 + 1][c2 + 1] - pre[r1][c2 + 1]
                    - pre[r2 + 1][c1] + pre[r1][c1])

        res = []
        for i, j in queries:
            lo, hi = 0, min(i, j, n - 1 - i, m - 1 - j)
            best = -1
            while lo <= hi:
                mid = (lo + hi) // 2
                if count(i - mid, j - mid, i + mid, j + mid) <= k:
                    best = mid
                    lo = mid + 1
                else:
                    hi = mid - 1
            res.append(2 * best + 1 if best >= 0 else -1)
        return res