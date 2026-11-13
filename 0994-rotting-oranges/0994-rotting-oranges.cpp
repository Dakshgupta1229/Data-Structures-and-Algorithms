class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int count = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        while(true){
            int n = q.size();
            if(n==0) break;
            bool flag = false;
            while(n--){
                int r = q.front().first;
                int c = q.front().second;
                grid[r][c] = 0;
                q.pop();
                if(r>=0 && c+1<grid[0].size() && grid[r][c+1]==1 && visited[r][c+1]!=1){
                    q.push({r,c+1});
                    visited[r][c+1] = 1;
                    flag = true;
                }
                if(r-1>=0 && c>=0 && grid[r-1][c]==1 && visited[r-1][c]!=1){
                    q.push({r-1,c});
                    visited[r-1][c] = 1;
                    flag = true;
                }
                if(r>=0 && c-1>=0 && grid[r][c-1]==1 && visited[r][c-1]!=1){
                    q.push({r,c-1});
                    visited[r][c-1] = 1;
                    flag = true;
                }
                if(r+1<grid.size() && c>=0 && grid[r+1][c]==1 && visited[r+1][c]!=1){
                    q.push({r+1,c});
                    visited[r+1][c] = 1;
                    flag = true;
                }
            }
            if(flag==true) count++;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return count;
    }
};