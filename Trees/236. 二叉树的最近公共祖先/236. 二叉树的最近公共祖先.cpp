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
        // 終止條件
        if(root == NULL || root == p ||root == q) return root;

        TreeNode* L = lowestCommonAncestor(root->left, p, q);
        TreeNode* R = lowestCommonAncestor(root->right, p, q);

        // 都不為NULL
        if(L != NULL && R != NULL) return root;
        // L為NULL
        else if(L == NULL && R != NULL) return R;
        // R為NULL
        else return L;
    }
};