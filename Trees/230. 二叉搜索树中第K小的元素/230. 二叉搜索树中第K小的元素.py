# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# preorder中序解法，差解
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

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# inorder中序解法，較佳
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        res = []
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()

            res.append(root.val)
            # k -= 1
            # if k == 0:
            #     return root.val

            root = root.right
        
        return res[k - 1]