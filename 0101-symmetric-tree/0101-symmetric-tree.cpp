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
    bool flag = true;
    void solve(TreeNode*root){
        if(root==NULL) return;
        deque<TreeNode*> q;
        q.push_back(root->left);
        q.push_back(root->right);
        while(!q.empty()){
            int n = q.size();
            deque<TreeNode*> dq = q;
            if(dq.size()%2==1){
                    flag = false;
                    return;
                }
             // cout << "hii";
            while(!dq.empty()){
                TreeNode*t1 = dq.front();
                dq.pop_front();
                TreeNode*t2 = dq.back();
                dq.pop_back();
                // cout << t1->val << " " << t2->val << "\n";
                if(!t1  && t2 || t1  && !t2){
                    flag = false;
                    return;
                }
                if(t1&&t2&&t1->val!=t2->val){
                    flag = false;
                    return;
                }
            }
            while(n--){
                TreeNode*t = q.front();
                q.pop_front();
                if(t){
                    q.push_back(t->left);
                    q.push_back(t->right);
                }
            }
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;
        if(root->left && !root->right || !root->left && root->right) return false;
        solve(root);
        return flag;
    }
};