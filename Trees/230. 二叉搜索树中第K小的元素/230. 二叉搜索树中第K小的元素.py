# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        res = []
        q = collections.deque()
        q.append(root)

        while q:
            sz = len(q)
            for i in range(sz):
                node = q.pop()

                if node.left : q.append(node.left)
                if node.right : q.append(node.right)

                res.append(node.val)
        
        res.sort()

        return res[k-1]