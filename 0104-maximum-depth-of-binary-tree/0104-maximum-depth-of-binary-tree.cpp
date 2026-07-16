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
    // int sum = 0;
    // int res = 0;
    int count(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = count(root->left);
        int right = count(root->right);

        // sum += left + right;
        // res = max(res, sum);

        return 1 + max(left, right);
    }

public:
    int maxDepth(TreeNode* root) { return count(root); }
};