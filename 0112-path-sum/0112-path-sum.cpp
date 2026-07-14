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
    bool ans = false;
    void add(TreeNode* root, int sum, int targetSum) {
        if (root == NULL) {
            return;
        }
        sum += root->val;
        // checking if the node is leaf
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                ans = true;
                return;
            }
        }
        add(root->left, sum, targetSum);
        add(root->right, sum, targetSum);
        return;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        add(root, sum, targetSum);
        return ans;
    }
};