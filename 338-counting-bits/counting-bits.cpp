class Solution {
public:
    vector<int> countBits(int n) {
        /*
        count of 1's in the binary representation of  an even number is 
        the same as the count for half of that number. The count for an 
        odd number is one more than the count for its preceding even number. */
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++){
            // if (i%2)
            //     dp[i] = dp[i/2] + 1;
            // else
            //     dp[i] = dp[i/2];
            // i&i == 1 if i is odd else 0
            dp[i] = dp[i/2] + (1&i);
        }
        return dp;
    }
};