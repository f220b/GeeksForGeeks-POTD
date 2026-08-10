class Solution:
    def maxTask(self, h: list[int], l: list[int]) -> int:
        n = len(h)
        if n == 0:
            return 0

        rest = 0                      # day 0 idle
        work = max(h[0], l[0])        # day 0 worked

        for i in range(1, n):
            best = max(rest, work)    # best regardless of yesterday's state
            new_rest = best
            new_work = max(rest + h[i], best + l[i])
            rest, work = new_rest, new_work

        return max(rest, work)