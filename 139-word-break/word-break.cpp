class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        
        // dp[i] means s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true; 
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; 
                }
            }
        }

        return dp[n];
    }
};