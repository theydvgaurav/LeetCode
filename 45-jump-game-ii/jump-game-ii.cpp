class Solution {
public:
    // int solve(vector<int> nums, int i){
    //     if (i>=nums.size()-1) return 0;
    //     if (dp[i]!=-1) return dp[i];
    //     int flag = nums.size();
    //     for(int j=1; j<=nums[i]; j++)
    //         flag = min(flag, 1 + solve(nums,i+j)) ;
    //     return dp[i] = flag;
    // }
    int jump(vector<int>& nums) {
         int n = nums.size();
        vector<int> dp(n, INT_MAX); 
        // dp[i] -> min number of steps that I need to come to this position.
        dp[0] = 0; // zeroth index doesn't need any step
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i && dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};