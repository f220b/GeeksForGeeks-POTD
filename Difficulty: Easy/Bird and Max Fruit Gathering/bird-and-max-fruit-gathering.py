class Solution:
    def maxFruits(self, arr: list[int], m: int) -> int:
        n = len(arr)

        window_sum = sum(arr[i % n] for i in range(m))
        max_total = window_sum

        for start in range(1, n):
            leaving = arr[start - 1]
            entering = arr[(start + m - 1) % n]
            window_sum += entering - leaving
            max_total = max(max_total, window_sum)

        return max_total
