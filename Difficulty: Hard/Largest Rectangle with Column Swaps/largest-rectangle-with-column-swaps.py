class Solution:
    def maxArea(self, mat: list[list[int]]) -> int:
        if not mat or not mat[0]:
            return 0
    
        n, m = len(mat), len(mat[0])
        heights = [0] * m
        best = 0
    
        for i in range(n):
            # build histogram for row i
            for j in range(m):
                heights[j] = heights[j] + 1 if mat[i][j] == 1 else 0
    
            # sort descending; k columns each of height >= sorted[k-1]
            order = sorted(heights, reverse=True)
            for k in range(m):
                if order[k] == 0:
                    break
                area = order[k] * (k + 1)
                if area > best:
                    best = area
    
        return best