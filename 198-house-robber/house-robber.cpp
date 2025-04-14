class Solution {
public:
    // vector<int> dp;
    // Solution() {
    //     dp = vector<int>(101, -1);
    // }
    // int solve(vector<int>& nums,int i){
    //     if(i >=nums.size()) return 0;
    //     if (dp[i]!=-1) return dp[i];
    //     return dp[i]=max(solve(nums,i+2) + nums[i],solve(nums,i+1));
    // }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        dp[1] = nums[0];
        for(int i=2; i<=nums.size(); i++){
            dp[i] = max(nums[i-1]+dp[i-2],dp[i-1]);
        }
        return dp[nums.size()];
    }
};