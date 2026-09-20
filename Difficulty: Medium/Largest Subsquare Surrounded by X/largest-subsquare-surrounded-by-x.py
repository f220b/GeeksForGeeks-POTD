class Solution:
    def largestSubsquare(self, mat):
        n = len(mat)
        if n == 0:
            return 0

        right = [[0] * (n + 1) for _ in range(n + 1)]
        down = [[0] * (n + 1) for _ in range(n + 1)]

        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if mat[i][j] == 'X':
                    right[i][j] = right[i][j + 1] + 1
                    down[i][j] = down[i + 1][j] + 1

        ans = 0
        for i in range(n):
            for j in range(n):
                limit = min(right[i][j], down[i][j])
                for k in range(limit, ans, -1):
                    if right[i + k - 1][j] >= k and down[i][j + k - 1] >= k:
                        ans = k
                        break
        return ans