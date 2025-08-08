class Solution {
public:
    void dfs(int start,vector<int> &visited, vector<vector<int>>& isConnected){
        visited[start] = 1;
        for(int i=0; i < isConnected[start].size(); i++){
            if (!visited[i] && isConnected[start][i] ){
                dfs(i,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<int> visited(n,0);
        for(int i=0; i<n;i++){
            if(!visited[i]){
                cnt+=1;
                dfs(i,visited,isConnected);
            }
        }
        return cnt;
    }
};