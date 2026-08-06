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
public:
    bool checkBST(TreeNode* root, long long mini, long long maxi) {
        if (!root)
            return true;

        if (root->val <= mini || root->val >= maxi)
            return false;

        return checkBST(root->left, mini, root->val) &&
               checkBST(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return checkBST(root, LLONG_MIN, LLONG_MAX);
    }
};