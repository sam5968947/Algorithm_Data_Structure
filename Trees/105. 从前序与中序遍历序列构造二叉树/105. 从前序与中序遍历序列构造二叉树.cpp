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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() or inorder.empty()) return NULL;

        TreeNode* node = new TreeNode(preorder[0]);
        int mid;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == preorder[0]){
                mid = i;
                break;
            }
        }

        vector<int> pre_l = vector<int>(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> pre_r = vector<int>(preorder.begin() + mid + 1, preorder.end());
        vector<int> in_l = vector<int>(inorder.begin(), inorder.begin() + mid);
        vector<int> in_r = vector<int>(inorder.begin() + mid + 1, inorder.end());

        node->left = buildTree(pre_l, in_l);
        node->right = buildTree(pre_r, in_r);

        return node;
    }
};