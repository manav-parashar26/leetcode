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
    TreeNode* help(vector<int>& inorder,int is,int ie, vector<int>& postorder,int ps,int pe,unordered_map<int,int>& mpp) {
        if(ps > pe || is > ie)return NULL;
        TreeNode* node = new TreeNode(postorder[pe]);
        int inroot = mpp[node->val];
        int numleft = inroot - is;
        node->left = help(inorder,is,inroot-1,postorder,ps,ps + numleft -1,mpp);
        node->right = help(inorder,inroot + 1,ie,postorder,ps + numleft,pe-1,mpp);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mpp;
        for(int i = 0;i < inorder.size();i++)mpp[inorder[i]] = i;
        return help(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }
};