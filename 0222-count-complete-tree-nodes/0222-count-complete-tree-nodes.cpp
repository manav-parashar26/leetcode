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
    int leftheight(TreeNode* root){
        int high = 0;
        while(root){
            high++;
            root = root->left;
        }
        return high;
    }
    int rightheight(TreeNode* root){
        int high = 0;
        while(root){
            high++;
            root = root->right;
        }
        return high;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int lh = leftheight(root);
        int rh = rightheight(root);
        if(lh == rh) return (1<<lh)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};