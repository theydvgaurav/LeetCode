class Solution {
public:
    int bfs(int n, vector<int>& indeg, vector<vector<int>>& adj) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[t]) {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }
        return cnt;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto it : prerequisites) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        return (bfs(numCourses, indeg, adj) == numCourses);
    }
};