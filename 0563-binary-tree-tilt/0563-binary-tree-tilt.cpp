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
    pair<int,int> solve(TreeNode *root){
        if(root==NULL) return {0,0};
        if(!root->left && !root->right) return {root->val,0};
        pair<int,int> l = solve(root->left);
        pair<int,int> r = solve(root->right);       
        return { l.first+r.first+root->val ,abs(l.first-r.first) + l.second + r.second}; 
    }
    int findTilt(TreeNode* root) {
        pair<int,int> p = solve(root);
        return p.second;
    }
};