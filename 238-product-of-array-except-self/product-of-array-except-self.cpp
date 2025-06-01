class Solution {
public:
    int getValue(int i, vector<int>& nums) {
        if (i < 0 || i >= nums.size())
            return 1;
        return nums[i];
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProd(n, 0), postfixProd(n, 0);
        int start = 1, end = 1;
        for (int i = 0; i < n; i++) {
            start *= getValue(i - 1, nums);
            prefixProd[i] = start;
            end *= getValue(n - i, nums);
            postfixProd[n - 1 - i] = end;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(prefixProd[i] * postfixProd[i]);
        }
        return res;
    }
};