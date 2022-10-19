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
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // 都不等於nullptr
        if(root == nullptr && subRoot == nullptr) return true;
        // 僅其中一個等於nullptr
        if(root == nullptr || subRoot == nullptr) return false;

        return isSameTree(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 都不等於nullptr
        if(p == nullptr && q == nullptr) return true;
        // 僅其中一個等於nullptr
        if(p == nullptr || q == nullptr) return false;

        return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};