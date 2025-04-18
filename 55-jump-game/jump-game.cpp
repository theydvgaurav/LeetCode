class Solution {
public:
    bool canJump(vector<int>& nums) {
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
        // for(auto it: dp)
        //     cout << it << " ";
        return dp[n - 1]==INT_MAX ? false : true;
    }
};