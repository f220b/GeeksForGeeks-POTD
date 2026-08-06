class Solution:
    def countMinOperations(self, arr):
        if not arr or max(arr) == 0:
            return 0

        total_increments = sum(bin(x).count('1') for x in arr)
        max_doublings = max(arr).bit_length() - 1

        return total_increments + max_doublings
