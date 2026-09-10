from math import gcd

class Solution:
    def pairCount(self, x: int, y: int) -> int:
        if y % x != 0:
            return 0

        m = y // x
        cnt = 0
        p = 1
        while p * p <= m:
            if m % p == 0:
                q = m // p
                if gcd(p, q) == 1:
                    cnt += 1 if p == q else 2
            p += 1

        return cnt