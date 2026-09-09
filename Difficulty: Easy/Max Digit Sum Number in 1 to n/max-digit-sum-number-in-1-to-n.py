class Solution:
    def findMax(self, n):
        s = str(n)
        L = len(s)

        total = sum(int(c) for c in s)
        best_sum, best_val = total, n

        prefix_sum = 0
        for i, ch in enumerate(s):
            d = int(ch)
            if d != 0:
                cand_sum = prefix_sum + (d - 1) + 9 * (L - i - 1)
                cand_val = int(s[:i] + str(d - 1) + '9' * (L - i - 1))
                if cand_val > 0 and (cand_sum, cand_val) > (best_sum, best_val):
                    best_sum, best_val = cand_sum, cand_val
            prefix_sum += d

        return best_val