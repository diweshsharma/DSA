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
    vector<vector<int>> res;
    void add(TreeNode* root, int sum, int targetSum ,vector<int> &temp) {
        
        if (root == NULL) {
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        // checking if the node is leaf
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                res.push_back(temp);
                temp.pop_back();
                return;
            }
        }
        add(root->left, sum, targetSum ,temp);
        add(root->right, sum, targetSum , temp);
        temp.pop_back();
        
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        add(root, sum, targetSum , temp);
        return res;
    }
};