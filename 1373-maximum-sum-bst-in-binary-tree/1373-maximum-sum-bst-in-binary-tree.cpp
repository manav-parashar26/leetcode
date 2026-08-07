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

class nodevalue {
public:
    int minnode, maxnode, sum;

    nodevalue(int minnode, int maxnode, int sum) {
        this->minnode = minnode;
        this->maxnode = maxnode;
        this->sum = sum;
    }
};

class Solution {
private:
    int ans = 0;

    nodevalue help(TreeNode* root) {
        if (!root)
            return nodevalue(INT_MAX, INT_MIN, 0);

        auto left = help(root->left);
        auto right = help(root->right);

        if (left.maxnode < root->val && root->val < right.minnode) {

            int sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);

            return nodevalue(min(left.minnode, root->val),
                             max(right.maxnode, root->val), sum);
        }

        return nodevalue(INT_MIN, INT_MAX, max(left.sum, right.sum));
    }

public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        help(root);
        return ans;
    }
};