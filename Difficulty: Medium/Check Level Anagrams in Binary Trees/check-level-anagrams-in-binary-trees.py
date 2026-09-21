"""
Structure of binary tree Node
class Node:
    def __init__(self, x: int):
        self.data = x
        self.left = self.right = None
"""
from collections import Counter

class Solution:
    def areAnagrams(self, root1, root2):
        if not root1 or not root2:
            return root1 is None and root2 is None

        level1, level2 = [root1], [root2]
        while level1 and level2:
            if Counter(n.data for n in level1) != Counter(n.data for n in level2):
                return False

            next1, next2 = [], []
            for node in level1:
                if node.left:  
                    next1.append(node.left)
                if node.right: 
                    next1.append(node.right)
            
            for node in level2:
                if node.left:  
                    next2.append(node.left)
                if node.right: 
                    next2.append(node.right)

            level1, level2 = next1, next2

        return not level1 and not level2
        return True if equal else False