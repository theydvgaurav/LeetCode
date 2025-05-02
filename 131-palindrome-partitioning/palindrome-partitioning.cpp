class Solution {
public:
    bool isPalindrome(string str, int left, int right) {
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(string s, int idx, vector<vector<string>>& res,
               vector<string> ds) {
        if (idx >= s.size()) {
            res.push_back(ds);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                ds.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, res, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        res.clear();
        vector<string> ds;
        ds.clear();
        solve(s, 0, res, ds);
        return res;
    }
};