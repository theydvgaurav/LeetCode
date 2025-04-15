class Solution {
public:
    vector<int> dp;
    vector<int> min_till_now;
    Solution(){
        dp = vector<int>(100001,-1);
    }
    int fn(vector<int>& prices,int i){
        if ( i >= prices.size()) return 0;
        int res = 0;
        for(int k=i+1; k < prices.size(); k++){
            res = max(prices[k] - prices[i],res);
        }
        return res;
    }
    int solve(vector<int>& prices,int i, vector<int>& min_till_now){
        if ( i >= prices.size()) return 0;
        if (dp[i]!=-1) return dp[i];
        return dp[i]=max(max(prices[i] - min_till_now[i],0),solve(prices,i+1,min_till_now));
    }
    void populate_min_till_now(vector<int> &prices, vector<int> &min_till_now){
        int m_till_now = prices[0];
        for(auto it: prices){
            m_till_now = min(m_till_now,it);
            min_till_now.push_back(m_till_now);
        } 
    }
    int maxProfit(vector<int>& prices) {
        min_till_now.clear();
        populate_min_till_now(prices,min_till_now);
        // for(auto it: min_till_now){
        //     cout << it << " ";
        // }
        // cout << "\n";
        return solve(prices,0,min_till_now);
    }
};