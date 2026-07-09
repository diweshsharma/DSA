/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void print(TreeNode* node , vector<int>&res) {
        if (node == nullptr) {
            return;
        }
        print(node->left ,res);
        // cout << node->val;
        res.push_back(node -> val);
        print(node->right ,res);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        print(root , res);
        return res;

    
    }
};