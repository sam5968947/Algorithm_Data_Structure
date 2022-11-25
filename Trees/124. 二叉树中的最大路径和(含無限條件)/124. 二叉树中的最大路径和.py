# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res = float('-inf')
    
    def dfs(self, root):
        # 終止條件
        if not root : return 0

        # 取左右節點最大值，若存在負數則為0(不走)
        l_max = max(self.dfs(root.left), 0)
        r_max = max(self.dfs(root.right), 0)

        # 更新解答
        self.res = max(self.res, root.val + l_max + r_max)

        # 如case1，若上面還有一個節點5，則1節點(為5的left，且無5的right)return值為1+3，最終解答會變為5+4
        return root.val + max(l_max, r_max)


    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.res