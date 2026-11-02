class Solution {
public:

    void dfs(int row,int column,vector<vector<int>> &grid,vector<vector<int>> &visited){
        visited[row][column] = 1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        for(int i=0;i<4;i++){
            int newrow = row + delrow[i];
            int newcol = column + delcol[i];
            if(newrow>=0 && newrow<grid.size() && newcol>=0 && newcol<grid[0].size() && visited[newrow][newcol]!=1 && grid[newrow][newcol]==1){
                dfs(newrow,newcol,grid,visited);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,visited);
            }
        }
        for(int i=0;i<grid.size();i++){
            if(grid[i][grid[0].size()-1]==1){
                dfs(i,grid[0].size()-1,grid,visited);
            }
        }
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1) dfs(0,i,grid,visited);
        }
        for(int i=0;i<grid[0].size();i++){
            if(grid[grid.size()-1][i]==1) dfs(grid.size()-1,i,grid,visited);
        }
        int count = 0;
        for(int i=0;i<visited.size();i++){
            for(int j=0;j<visited[i].size();j++){
                if(visited[i][j]==0 && grid[i][j]==1) count++;
            }
        }
        return count;
    }
};