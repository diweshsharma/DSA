/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* ans = nullptr;

    void search(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return;
        }
        if (root-> val == p-> val && root->val == q->val) {
            ans = root;
            return;
        }
        if (root->val < p->val && root->val < q->val) {
            search(root->right, p, q);
        } else if (root->val > q->val) {
            search(root->left, p, q);
        } else {
            ans = root;
            return;
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p -> val < q -> val){
            search(root , p ,q);
        }
        else{
            search(root , q , p);
        }
        return ans;
    }
};