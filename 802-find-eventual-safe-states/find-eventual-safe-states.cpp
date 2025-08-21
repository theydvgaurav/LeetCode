class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& check,
             vector<int>& pathVis, vector<int>& vis) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, graph, check, pathVis, vis))
                    return true;
            } else if (pathVis[it]) {
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> check(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> vis(n, 0);
        vector<int> res;
        res.clear();
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, check, pathVis, vis);
            }
        }
        for (int i = 0; i < n; i++) {
            if (check[i] == 1) {
                res.push_back(i);
            }
        }
        return res;
    }
};