class Solution {
public:
    vector<int> dp;
    int solve(vector<int> cost, int i, int tgt){
        if(i >= tgt) return 0;
        if (dp[i]!=1e9) return dp[i];
        return dp[i] = cost[i] + min(solve(cost,i+1,tgt), solve(cost,i+2,tgt));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp = vector<int>(cost.size()+1,1e9);
        int res = solve(cost,0,cost.size());
        dp = vector<int>(cost.size()+1,1e9);
        return min(res,solve(cost,1,cost.size()));
    }
};