class Solution {
public:

    void bfs(int row,int column,vector<vector<char>> &grid,vector<vector<int>> &visited){
        queue<pair<int,int>> q;
        q.push({row,column});
        visited[row][column] = 1;
        while(q.size()>0){
            int r1 = q.front().first;
            int c1 = q.front().second;
            q.pop();
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,-1,0,1};
                for(int i=0;i<4;i++){
                    int n_row1 = r1 + delrow[i];
                    int n_col1 = c1 + delcol[i];
                    if(n_row1>=0 && n_col1>=0 && n_row1<grid.size() && n_col1<grid[0].size() && grid[n_row1][n_col1]=='1' && visited[n_row1][n_col1]!=1){
                        q.push({n_row1,n_col1});
                        visited[n_row1][n_col1] = 1;
                    }
                }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};