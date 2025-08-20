class Solution {
public:
    int bfs(int n, vector<vector<int>>& adj) {
        vector<int> indeg(n, 0);
        for (auto it : adj) {
            for (auto itr : it) {
                indeg[itr]++;
            }
        }
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
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        return (bfs(numCourses, adj) == numCourses);
    }
};