class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            int take = nums[i] + (i + 2 < n ? dp[i + 2] : 0);
            int skip = dp[i + 1];
            dp[i] = max(take, skip);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // if only one elem is there
        vector<int> case1(nums.begin(), nums.end() - 1); // 0...n-2
        vector<int> case2(nums.begin() + 1, nums.end()); // 1...n-1
        return max(solve(case1), solve(case2));
    }
};
