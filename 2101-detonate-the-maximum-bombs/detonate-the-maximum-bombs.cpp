class Solution {
public:
    int bfs(int src, vector<vector<int>>& adj) { 
        queue<int> q;
        vector<int> visited(adj.size(),0);
        visited[src] = 1;
        q.push(src);
        int cnt = 1;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto it: adj[t]){
                if (!visited[it]){
                    visited[it] = 1; 
                    q.push(it);
                    cnt+=1;
                }
            }
        }
        return cnt;
    
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long dx = x1 - x2, dy = y1 - y2;
                if (dx * dx + dy * dy <= r * r) {
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, bfs(i, adj));
        }
        return ans;
    }
};