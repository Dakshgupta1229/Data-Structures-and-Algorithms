class Solution {
public:

    void dfs(int node,vector<vector<int>> &isConnected,vector<int> &visited){
        visited[node] = 1;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node-1][i]==1){
                if(visited[i+1]==0){
                    visited[i+1] = 1;
                    dfs(i+1,isConnected,visited);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size()+1);
        int count = 0;
        for(int i=1;i<visited.size();i++){
            if(visited[i]==0){
                dfs(i,isConnected,visited);
                count++;
            }
        }
        return count;
    }
};