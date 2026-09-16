from bisect import bisect_left

class Solution:
    def dominantPairs(self, arr: list[int]) -> int:
        n = len(arr)
        temp1, temp2 = arr[: n // 2], arr[n // 2 :]
        temp1.sort()

        count = 0
        for x in temp2:
            # elements of temp1 that are >= 5*x
            count += len(temp1) - bisect_left(temp1, 5 * x)
        return count