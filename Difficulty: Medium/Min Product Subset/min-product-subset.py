class Solution:
    def minProd(self, arr):
        prod = 1
        neg_count = 0
        max_neg = float('-inf')   # negative closest to zero
        has_zero = False
    
        for x in arr:
            if x == 0:
                has_zero = True
                continue
            if x < 0:
                neg_count += 1
                max_neg = max(max_neg, x)
            prod *= x
    
        if neg_count == 0:
            return 0 if has_zero else min(arr)
    
        if neg_count % 2 == 0:
            prod //= max_neg   # exact division, remainder is 0
    
        return prod