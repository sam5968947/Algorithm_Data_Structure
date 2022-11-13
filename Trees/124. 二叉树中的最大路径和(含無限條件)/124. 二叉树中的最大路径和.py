# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # python class內全域變數宣告方式，也可於main func內用list替代(python list為全域變數)
    def __init__(self):
        # 若節點為單一節點必須走-->ex: -3
        self.maxSum = float("-inf")

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if not root : return 0

            #取左右子節點最大路徑長，若有負數則取0(不走此節點)
            l_max = dfs(root.left)
            r_max = dfs(root.right)
            l_max = max(l_max, 0)
            r_max = max(r_max, 0)

            #更新解答
            self.maxSum = max(self.maxSum, root.val + l_max + r_max)

            return root.val + max(l_max, r_max)

        dfs(root)
        return self.maxSum