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
    // string res = "";
    string preorder(TreeNode*root){
        if(root==NULL) return " ";
        string s = to_string(root->val); 
        string l = preorder(root->left);
        string r = preorder(root->right);
        if(l[0]!=' ') s+="(" + l + ")";
        else if (l[0]==' ' && r[0]!=' ') s+="()";
        if(r[0]!=' ') s+="(" + r + ")";
        return s;
    }
    
    string tree2str(TreeNode* root) {
        // res+=to_string(root->val);
        string res = preorder(root);
        return res;
        
    }
};