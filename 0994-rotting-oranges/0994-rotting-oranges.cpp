class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int count = 0;
        while(q.size()>0){
            bool flag = false;
            int n = q.size();
            while(n--){
                int row = q.front().first;
                int column = q.front().second;
                q.pop();
                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,-1,0,1};
                for(int i=0;i<4;i++){
                    int newrow = row + delrow[i];
                    int newcol = column + delcol[i];
                    if(newrow>=0 && newrow<grid.size() && newcol>=0 && newcol<grid[0].size() && grid[newrow][newcol]==1 && visited[newrow][newcol]!=1){
                        grid[newrow][newcol] = 2;
                        visited[newrow][newcol] = 1;
                        q.push({newrow,newcol});
                        flag = true;
                    }
                }
            }
            if(flag==true) count++;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return count;
    }
};