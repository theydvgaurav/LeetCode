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
    vector<vector<int>> v;
    void bfs(TreeNode*root){
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            while(n--){
                TreeNode *t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            v.push_back(temp);
        }
    }
        
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        v.clear();
        bfs(root);
        reverse(v.begin(),v.end());
        return v;
    }
};