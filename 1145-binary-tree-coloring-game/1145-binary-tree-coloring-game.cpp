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
    int x_l = 0, x_r = 0;
    int subtreeSize(TreeNode*root, int x){
        if(root==NULL) return 0;
        
        int l = subtreeSize(root->left,x);
        int r = subtreeSize(root->right,x);
        
        if(root->val==x){
            x_l = l; 
            x_r = r;
        }
        return l + r + 1;
    }    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int size = subtreeSize(root,x);
        int Rem = size - (x_l + x_r +1);
        if((Rem > (x_l + x_r +1)) || (x_l > (Rem + x_r +1)) || (x_r > (Rem+1+x_l))) return true;
        
        return false;
    }
};