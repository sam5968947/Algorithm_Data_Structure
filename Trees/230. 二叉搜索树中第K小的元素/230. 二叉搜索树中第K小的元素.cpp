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

// preorder中序解法，差解
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // init
        vector<int> all_v;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                // node為q最前的一個元素
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);

                all_v.push_back(node->val);
            }
        }

        sort(all_v.begin(), all_v.begin() + all_v.size());

        return all_v[k - 1];
    }
};

// inorder中序解法，較佳
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        if (root == nullptr) return 0;
        stack<TreeNode *> s;

        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            } 

            TreeNode *node = s.top();
            s.pop();
            res.push_back(node->val);
            root = node->right;
        }

        return res[k - 1];
    }
};