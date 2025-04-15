class Solution {
public:
    vector<int> dp;
    vector<int> min_till_now;
    Solution(){
        dp = vector<int>(100001,-1);
    }
    int solve(vector<int>& prices,int i, int min_so_far){
        if ( i >= prices.size()) return 0;
        if (dp[i]!=-1) return dp[i];
        int profit_if_sell_today = max(prices[i] - min_so_far,0);
        min_so_far = min(min_so_far,prices[i]);
        return dp[i]=max(profit_if_sell_today,solve(prices,i+1,min_so_far));
    }
    // void populate_min_till_now(vector<int> &prices, vector<int> &min_till_now){
    //     int m_till_now = prices[0];
    //     for(auto it: prices){
    //         m_till_now = min(m_till_now,it);
    //         min_till_now.push_back(m_till_now);
    //     } 
    // }
    int maxProfit(vector<int>& prices) {
        // min_till_now.clear();
        // populate_min_till_now(prices,min_till_now);
        return solve(prices,0,prices[0]);
    }
};