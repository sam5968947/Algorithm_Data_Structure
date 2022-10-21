# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 終止條件
        if not root or root == p or root == q : return root

        L = self.lowestCommonAncestor(root.left, p, q)
        R = self.lowestCommonAncestor(root.right, p, q)

        # L、R皆存在
        if L and R : return root
        # 僅L存在，R為空
        elif not R : return L
        # 僅R存在，L為空
        else : return R