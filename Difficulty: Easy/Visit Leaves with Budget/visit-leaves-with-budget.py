''' Binary Tree Node Structure
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def getCount(self, root, k):
        if not root:
            return 0

        depths = []

        # iterative DFS to avoid recursion depth issues on skewed trees
        stack = [(root, 1)]
        while stack:
            node, level = stack.pop()
            if not node.left and not node.right:
                depths.append(level)
                continue
            if node.left:
                stack.append((node.left, level + 1))
            if node.right:
                stack.append((node.right, level + 1))

        depths.sort()

        total = 0
        count = 0
        for d in depths:
            if total + d > k:
                break
            total += d
            count += 1

        return count