class Solution {
public:
    int solve(int n, int i, vector<int> &dp){
        if (i==n) return 1;
        if (i > n) return 0;
        if (dp[i+1]==-1)
            dp[i+1] = solve(n,i+1,dp);
        if (dp[i+2]==-1)
            dp[i+2] = solve(n,i+2,dp);
        return  dp[i+1] + dp[i+2];
    }
    int climbStairs(int n) {
        vector<int> dp(3*n,-1);
        return solve(n,0,dp);
    }
};