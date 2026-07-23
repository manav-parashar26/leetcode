/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int s = q.size();
            vector<int> row(s);
            for(int i = 0;i <s;i++){
                TreeNode* node = q.front();
                q.pop();
            int x = (flag)?i:(s-i-1);
            row[x] = node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            flag = !flag;
            ans.push_back(row);
        }
        return ans;
    }
};