class Solution {
public:

    void bfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int row,int column){
        visited[row][column] = 1;
        queue<pair<int,int>> q;
        q.push({row,column});
        while(q.size()>0){
            int r = q.front().first;
            int c = q.front().second;
            grid[r][c] = '0';
            q.pop();
            if(r-1>=0 && r<grid.size() && c>=0 && c<grid[0].size() && visited[r-1][c]!=1 && grid[r-1][c]=='1'){
                q.push({r-1,c});
                visited[r-1][c] = 1;
            }
            if(r>=0 && r<grid.size() && c-1>=0 && c<grid[0].size() && visited[r][c-1]!=1 && grid[r][c-1]=='1'){
                q.push({r,c-1});
                visited[r][c-1] = 1;
            }
            if(r+1<grid.size() && r>=0 && c>=0 && c<grid[0].size() && grid[r+1][c]=='1' && visited[r+1][c]!=1){
                q.push({r+1,c});
                visited[r+1][c] = 1;
            }
            if(r>=0 && r<grid.size() && c>=0 && c+1<grid[0].size() && grid[r][c+1]=='1' && visited[r][c+1]!=1){
                q.push({r,c+1});
                visited[r][c+1] = 1;
            }
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && visited[i][j]!=1){
                    bfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};