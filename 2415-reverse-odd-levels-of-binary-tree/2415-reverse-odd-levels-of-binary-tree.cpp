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
    void bfs(TreeNode*root){
        if(root==NULL) return;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int depth=0;
        while(!q.empty()){
            int n = q.size();
            if(depth%2==1){
                queue<pair<TreeNode*,int>> q2 = q;
                stack<int> s;
                while(!q2.empty()){
                    pair<TreeNode*, int> t = q2.front();
                    q2.pop();
                    s.push(t.first->val);
                }
                
                while(n--){
                    pair<TreeNode*,int> t = q.front();
                    q.pop();
                    int x = s.top(); s.pop();
                    t.first->val = x;
                    if(t.first->left) q.push({t.first->left,t.second+1});
                    if(t.first->right) q.push({t.first->right,t.second+1});
                }
            }
            else{
                while(n--){
                    pair<TreeNode*,int> t = q.front();
                    q.pop();
                    if(t.first->left) q.push({t.first->left,t.second+1});
                    if(t.first->right) q.push({t.first->right,t.second+1});
                }
            }
            depth++;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        bfs(root);
        return root;
    }
};