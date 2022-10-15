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
    bool flag = false;
    bool isSameTree(TreeNode*t1,TreeNode*t2)
    {
        if(!t1&&!t2) return true;
        if(!t1&&t2 || t1&&!t2) return false;
        return isSameTree(t1->left,t2->left) && isSameTree(t1->right,t2->right) && (t1->val==t2->val);
    }    
    
    void solve(TreeNode*root, TreeNode*subRoot){
       if(root==NULL) return;
       if(root->val==subRoot->val){
           cout << root->val << " -x- " << subRoot->val;
            flag = flag || isSameTree(root,subRoot);
       }
       solve(root->left,subRoot); 
       solve(root->right,subRoot); 
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       
        if(!root && !subRoot) return true;
         // cout << root->val << " -gh- " << subRoot->val << endl;
        if(root && !subRoot) return true;
         // cout << root->val << " -2- " << subRoot->val << endl;
        if(!root && subRoot) return false;
         // cout << root->val << " -3- " << subRoot->val << endl;
        solve(root,subRoot);
        return flag;
    }
};