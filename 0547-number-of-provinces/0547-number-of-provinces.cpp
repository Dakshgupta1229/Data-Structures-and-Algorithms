class Solution {
public:

    void bfs(int node,vector<int> &visited,vector<vector<int>> &adj){
        visited[node] = 1;
        queue<int> q;
        q.push(node);
        while(q.size()>0){
            int value = q.front();
            q.pop();
            for(int i=0;i<adj[value].size();i++){
                int element = adj[value][i];
                if(visited[element]==0){
                    visited[element] = 1;
                    q.push(element);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> v(isConnected.size()+1);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    v[i+1].push_back(j+1);
                }
            }
        }
        vector<int> visited(isConnected.size()+1);
        int count = 0;
        for(int i=1;i<visited.size();i++){
            if(visited[i]==0){
                bfs(i,visited,v);
                count++;
            }
        }
        return count;
    }
};