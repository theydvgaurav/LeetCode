class Solution {
public:
    void solve(vector<int> nums,int idx, vector<vector<int>> &res){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=idx; i < nums.size(); i++){ // I try to place all the items at idx 
            swap(nums[idx],nums[i]);
            solve(nums,idx+1,res); // idx + 1 because I finished operations on idx not i
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums,0,res);
        return res;
    }
};