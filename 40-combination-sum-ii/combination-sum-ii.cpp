class Solution {
public:
    void solve(vector<int> can, int target, int idx, vector<vector<int>>& res,
               vector<int>& ds) {
        if (target == 0) {
            res.push_back(ds);
            return;
        }

        for (int i = idx; i < can.size(); i++) {
            if (can[i] > target)
                break;
            if (i > idx && can[i] == can[i - 1])
                continue;
            ds.push_back(can[i]);
            solve(can, target - can[i], i + 1, res, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, res, ds);
        return res;
    }
};