/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // p、q在root左
        if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);

        // p、q在root右
        else if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);

        else return root;
    }
};