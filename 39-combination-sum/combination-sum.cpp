class Solution {
public:
    void solve(vector<int> candidates, int target, int idx, int curr_sum, vector<vector<int>> &res, vector<int> &temp){
        if (curr_sum > target) return;
        if (idx >= candidates.size()){
            if(target == curr_sum) res.push_back(temp);
            return;
        }
        // picking -> not increasing the idx because I can pick any element any number of times
        temp.push_back(candidates[idx]);
        solve(candidates,target,idx,curr_sum+candidates[idx],res,temp);
        temp.pop_back();

        // not picking
        solve(candidates,target,idx+1,curr_sum,res,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> res;
       vector<int> temp;
       solve(candidates,target,0,0,res,temp);
       return res; 
    }
};