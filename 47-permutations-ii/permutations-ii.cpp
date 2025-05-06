class Solution {
public:
    void solve(vector<int> nums,int idx, set<vector<int>> &res){
        if(idx==nums.size()){
            res.insert(nums);
            return;
        }
        for(int i=idx; i < nums.size(); i++){ // I try to place all the items at idx 
            swap(nums[idx],nums[i]);
            solve(nums,idx+1,res); // idx + 1 because I finished operations on idx not i
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        solve(nums,0,res);
        vector<vector<int>> ans;
        for(auto it: res){
            ans.push_back(it);
        }
        return ans;
    }
};
