/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

public:
    TreeNode* dfs(istringstream& vals){
        string s;
        vals>>s;//s為迭代第一個元素，類似pop(0)

        if(s == "N") return NULL;

        TreeNode* node = new TreeNode(stoi(s));
        node->left = dfs(vals);
        node->right = dfs(vals);

        return node;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // 中止條件
        if(root == nullptr) return "N";

        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // istringstream將字串變成字串迭代器stream，默認" "為分割對象
        istringstream stream(data);

        return dfs(stream);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));