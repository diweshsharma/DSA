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

/* it is like brute force solution */
class Solution {
private:
    void print(TreeNode* node, vector<int>& res) {
        if (node == nullptr) {
            return;
        }
        print(node->left, res);
        res.push_back(node->val);
        print(node->right, res);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        vector<int> res;
        print(root, res);
        int i = 0;
        int j = res.size() - 1;
        while (i < j) {
            if (res[i] + res[j] == k) {
                return true;
            } else if (res[i] + res[j] < k) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};