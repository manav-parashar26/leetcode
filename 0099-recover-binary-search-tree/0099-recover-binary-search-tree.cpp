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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev;

    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        check(root);
        inorder(root->right);
    }

    void check(TreeNode* node) {
        if (prev && prev->val > node->val) {
            if (!first) {
                first = prev;
            }
            second = node;
        }
        prev = node;
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};