class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if ((i + j) < n) {
                    dp[i + j] = min(dp[i] + 1, dp[i + j]);
                }
            }
        }
        return (dp[n-1] == 1e9) ? false : true;
    }
};