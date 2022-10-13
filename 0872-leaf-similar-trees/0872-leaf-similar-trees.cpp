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
    void solve(TreeNode* root, vector<int> &v){
        if(root==NULL) return;
        solve(root->left,v);
        if(!root->left && !root->right){
            v.push_back(root->val);
        }
        solve(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;  
        vector<int> v2;
        v1.clear();
        v2.clear();
        solve(root1,v1);
        solve(root2,v2);
        
        for(auto it : v1) cout << it << " ";
        cout << "\n";
        for(auto it : v2) cout << it << " ";
        
        
        if(v1.size()!=v2.size()) return false;
        for(int i = 0;  i < v1.size(); i++){
            if(v1[i]!=v2[i]){
                return false;
                break;
            }
        }
        return true;
    }
};