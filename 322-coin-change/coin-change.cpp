class Solution {
public:
    vector<long long int> dp;
    Solution(){
        dp = vector<long long int>(10001,-1);
    }
    long long int solve(vector<int> coins, long long tgt, long long int curr_sum){
        if (curr_sum > tgt) return 1e9;
        if (curr_sum==tgt) return 0;
        if (dp[curr_sum]!=-1) return dp[curr_sum];
        long long int temp = 1e9;
        for(auto it: coins){
            temp = min(temp, 1 + solve(coins,tgt,curr_sum+it));
        }
        return dp[curr_sum] = temp;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        long long int res = solve(coins, amount, 0);
        return res>=1e9?-1:res;
    }
};