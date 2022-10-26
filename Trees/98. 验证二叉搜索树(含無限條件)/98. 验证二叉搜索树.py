# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        temp = float('-inf')
        stk = []

        while root or stk:
            while root:
                stk.append(root)
                root = root.left
            
            node = stk.pop()

            if node.val <= temp:
                return False
            temp = node.val

            root = node.right
        
        return True