class Solution:
    def minMoves(self, arr):
        n = len(arr)
        count = [0] * (n + 1)
    
        for x in arr:
            if count[x - 1]!= 0:
                count[x] = count[x - 1] + 1
            else:
                count[x] = 1
    
        longest = 0
    
        for i in range(n + 1):
            longest = max(longest, count[i])
    
        return n - longest