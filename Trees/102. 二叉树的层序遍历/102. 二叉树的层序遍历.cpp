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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 打印題型
        // 初始化
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        if(root == nullptr) return res;

        while(!q.empty()){
            vector<int> temp;
            int sz = q.size();
            
            for(int i= 0; i < sz;i++){
                // node為q的第一個元素
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            res.push_back(temp);
        }

        return res;
    }
};