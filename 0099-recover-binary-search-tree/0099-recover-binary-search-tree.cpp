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
    int wrong = 0;
    TreeNode* prev = NULL;
    TreeNode* wrong1first = NULL;
    TreeNode* wrong1second = NULL;
    TreeNode* wrong2first = NULL;
    TreeNode* wrong2second = NULL;
    void recover(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        recover(root->left);
        if (prev == NULL) {
            prev = root;
        } else {
            if (root->val <= prev->val) {
                if (wrong == 0) {
                    wrong1first = prev;
                    wrong1second = root;
                    wrong++;
                } else {
                    wrong2first = prev;
                    wrong2second = root;
                    wrong++;
                }
            }
            prev = root;
        }
        recover(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        recover(root);
        if (wrong == 1) {
            swap(wrong1first->val, wrong1second->val);
        } else {
            
            swap(wrong1first->val, wrong2second->val);
            
        }
        return;
    }
};