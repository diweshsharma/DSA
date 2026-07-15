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
    int res = 0;
    void add(TreeNode* root, int sum) {
        if (root == NULL) {
            return;
        }
        sum = sum * 10 + root->val;
        // checking if the node is leaf
        if (root->left == NULL && root->right == NULL) {

            res += sum;
            return;
        }
        add(root->left, sum);
        add(root->right, sum);
        return;
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        add(root, sum);
        return res;
    }
};