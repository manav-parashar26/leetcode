/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node)s.append("#,");
            else s.append(to_string(node->val)+",");
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        } 
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)return NULL;
        stringstream ss(data);
        string s;
        getline(ss, s, ',');
        if (s == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!getline(ss, s, ',')) break;
            if(s == "#")node->left = NULL;
            else{
                TreeNode* leftnode = new TreeNode(stoi(s));
                node->left = leftnode;
                q.push(leftnode);
            }
            if(!getline(ss, s, ',')) break;
            if(s == "#")node->right = NULL;
            else{
                TreeNode* rightnode = new TreeNode(stoi(s));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));