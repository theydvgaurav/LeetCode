class Solution {
public:
    void dfs(int start, int par, vector<int> &visited, vector<vector<int>>& adj){
        visited[start] = 1;
        for(auto it:adj[start]){
            if (!visited[it] && it!=par ){
                dfs(it,start,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<vector<int>> adj(n + 1, vector<int>(0));
        for(int i=0; i<n; i++){
            for(int j=0; j<isConnected[i].size(); j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n+1,0);
        for(int i=0; i<n;i++){
            if(!visited[i]){
                cnt+=1;
                dfs(i,-1,visited,adj);
            }
        }
        return cnt;
    }
};