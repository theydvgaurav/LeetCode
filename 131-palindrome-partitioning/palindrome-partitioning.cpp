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
    void backtrack(string s, int idx, vector<vector<string>>& res,
               vector<string> ds) {
        if (idx >= s.size()) {
            res.push_back(ds);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            // only consider the substrings which are palindrome in itself, and then use the substrings after that. 
            if (isPalindrome(s, idx, i)) {
                ds.push_back(s.substr(idx, i - idx + 1));
                backtrack(s, i + 1, res, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(s, 0, res, path);
        return res;
    }
};