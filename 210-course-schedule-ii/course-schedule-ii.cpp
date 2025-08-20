class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res, indeg(numCourses, 0);
        res.clear();
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for (auto it : adj[t]) {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }
        reverse(res.begin(), res.end());
        return (res.size() == numCourses) ? res : vector<int>();
    }
};