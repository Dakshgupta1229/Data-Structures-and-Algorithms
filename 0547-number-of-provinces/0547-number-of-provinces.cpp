class Solution {
public:

    void dfs(vector<vector<int>> &adj,vector<int> &visited,int start){
        visited[start] = 1;
        vector<int> v1 = adj[start];
        for(int i=0;i<v1.size();i++){
            int ele = v1[i];
            if(visited[ele]!=1){
                dfs(adj,visited,ele);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(visited[i]!=1){
                count++;
                dfs(adj,visited,i);
            }
        }
        return count;
    }
};