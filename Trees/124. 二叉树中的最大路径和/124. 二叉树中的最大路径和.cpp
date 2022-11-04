/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

// C++ class內全域變數宣告方式，等同於python def __init__(self):
private:
    // 若節點為單一節點必須走-->ex: -3
    int res = INT_MIN;

private:
    int dfs(TreeNode* root) {
        // 中止條件
        if(root == nullptr) return 0;

        // 取左右節點最大值，若存在負數則為0(不走)
        int l_max = max(dfs(root->left), 0);
        int r_max = max(dfs(root->right), 0);

        // 更新res
        res = max(res, root->val + l_max + r_max);

        return root->val + max(l_max, r_max);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

};