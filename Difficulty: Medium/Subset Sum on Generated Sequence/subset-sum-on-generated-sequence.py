class Solution:
    def isPossible(self, arr, s, x):
        paper = [s]
        total = s
        for a in arr:
            curr = total + a
            paper.append(curr)
            total += curr

        rem = x
        for val in reversed(paper):
            if val <= rem:
                rem -= val
            if rem == 0:
                return True
        return rem == 0