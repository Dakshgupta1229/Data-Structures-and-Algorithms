class Solution {
public:

    void bfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>> &grid){
        visited[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(q.size()>0){
            auto it = q.front();
            q.pop();
            int i1 = it.first;
            int j1 = it.second;
            if(i1-1>=0 && grid[i1-1][j1]=='1' && visited[i1-1][j1]==0){
                visited[i1-1][j1] = 1;
                q.push({i1-1,j1}); 
            }
            if(i1+1<grid.size() && grid[i1+1][j1]=='1' && visited[i1+1][j1]==0){
                visited[i1+1][j1] = 1;
                q.push({i1+1,j1}); 
            }
            if(j1-1>=0 && grid[i1][j1-1]=='1' && visited[i1][j1-1]==0){
                visited[i1][j1-1] = 1;
                q.push({i1,j1-1}); 
            }
            if(j1+1<grid[0].size() && grid[i1][j1+1]=='1' && visited[i1][j1+1]==0){
                visited[i1][j1+1] = 1;
                q.push({i1,j1+1}); 
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    bfs(i,j,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};