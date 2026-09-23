class Solution:
    def formPyramid(self, arr):
        n = len(arr)

        L = [0] * n
        prev = 0
        for i in range(n):
            prev = min(arr[i], prev + 1)
            L[i] = prev

        best = 0
        prev = 0
        for i in range(n - 1, -1, -1):
            prev = min(arr[i], prev + 1)
            best = max(best, min(L[i], prev))

        return sum(arr) - best * best