class Solution:
    def maxDiffSum(self, arr):
        n = len(arr)
        if n < 2:
            return 0
    
        keep = one = 0          # states for index 0
        for i in range(1, n):
            prev, cur = arr[i - 1], arr[i]
            new_keep = max(keep + abs(cur - prev), one + abs(cur - 1))
            new_one  = max(keep + abs(1 - prev),   one)
            keep, one = new_keep, new_one
    
        return max(keep, one)