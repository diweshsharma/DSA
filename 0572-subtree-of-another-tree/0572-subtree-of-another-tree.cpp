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
    bool same(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) {
            return true;
        }
        if (root == NULL || subRoot == NULL) {
            return false;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        bool left = same(root->left, subRoot->left);
        bool right = same(root->right, subRoot->right);
        if (left == true && right == true) {
            return true;
        }
        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        if (root == NULL) {
            return false;
        }
        if (same(root , subRoot)) {
            return true;
            
        }
        
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};