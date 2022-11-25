# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        # 中止條件
        if not root : return 'N'
        
        return str(root.val) + ',' + self.serialize(root.left) + ',' + self.serialize(root.right)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        # print(data)
        vals = data.split(',')
        # print(vals)

        # preorder順序 : 中->左->右
        def dfs(vals):
            val = vals.pop(0)
            # 中止條件
            if val == 'N' : return None
            node = TreeNode(int(val))
            node.left = dfs(vals)
            node.right = dfs(vals)

            return node

        return dfs(vals)
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))