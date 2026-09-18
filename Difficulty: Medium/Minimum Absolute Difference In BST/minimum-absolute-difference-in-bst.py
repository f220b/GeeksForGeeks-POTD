'''
Binary Tree Node Structure
class Node:
    def __init__(self):
        self.data = None
        self.left = None
        self.right = None
'''
        
class Solution:
    def absDiff(self, root):
        self.prev = None
        self.ans = float('inf')

        def inorder(node):
            if not node or self.ans == 0:
                return
            inorder(node.left)
            if self.prev is not None:
                self.ans = min(self.ans, node.data - self.prev)
            self.prev = node.data
            inorder(node.right)

        inorder(root)
        return self.ans