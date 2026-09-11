from math import gcd

class Solution:
    def sameMod(self, arr):
        n = len(arr)
        g = 0
        
        for i in arr:
            g = gcd(g, abs(i - arr[0]))
        
        if g == 0:
            return -1
            
        cnt = 0
        for i in range(1, int(g**0.5)+1):
            if g % i == 0:
                cnt += 1
                if i != g // i:
                    cnt += 1
        
        return cnt