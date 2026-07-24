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
    void findst(TreeNode* root, string s, vector<string>& ans) {
        if (!root)
            return;

        if (!s.empty())
            s += "->";
        s += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(s);
            return;
        }

        findst(root->left, s, ans);
        findst(root->right, s, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root)
            return ans;
        findst(root, "", ans);
        return ans;
    }
};