from bisect import bisect_left
from typing import List

class Solution:
    def getMarks(self, l: List[int], r: List[int], rank: List[int]) -> List[int]:
        n = len(l)

        # prefix[i] = total count of marks in intervals 0..i (inclusive)
        prefix = [0] * n
        running = 0
        for i in range(n):
            running += (r[i] - l[i] + 1)
            prefix[i] = running

        total = prefix[-1] if n > 0 else 0

        result = []
        for k in rank:
            if k < 1 or k > total:
                result.append(-1)  # invalid rank, adjust as per problem constraints
                continue

            # find the smallest index i such that prefix[i] >= k
            idx = bisect_left(prefix, k)

            # marks before this interval
            prev_count = prefix[idx - 1] if idx > 0 else 0

            # offset within this interval (0-indexed)
            offset = k - prev_count - 1

            mark = l[idx] + offset
            result.append(mark)

        return result