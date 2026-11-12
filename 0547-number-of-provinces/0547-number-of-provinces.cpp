class Solution {
public:

    void bfs(vector<vector<int>> &adj,vector<int> &visited,int start){
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while(q.size()>0){
            int ele = q.front();
            q.pop();
            for(int i=0;i<adj[ele].size();i++){
                int value = adj[ele][i];
                if(visited[value]!=1){
                    q.push(value);
                    visited[value] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size()+1);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int count = 0;
        vector<int> visited(adj.size(),0);
        for(int i=1;i<adj.size();i++){
            if(visited[i]!=1){
                count++;
                bfs(adj,visited,i);
            }
        }
        return count;
    }
};