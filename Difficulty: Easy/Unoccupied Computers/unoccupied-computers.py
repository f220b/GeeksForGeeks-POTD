class Solution:
    def solve(self, n, s):
        seen = [False] * 26        # has this letter's arrival been processed?
        has_computer = [False] * 26
        available = n
        not_assigned = 0
    
        for ch in s:
            idx = ord(ch) - ord('A')
            if seen[idx]:
                # this is the departure event
                if has_computer[idx]:
                    available += 1
                    has_computer[idx] = False
                # if they never got a computer, departure just frees nothing
            else:
                # this is the arrival event
                seen[idx] = True
                if available > 0:
                    has_computer[idx] = True
                    available -= 1
                else:
                    not_assigned += 1
    
        return not_assigned