class Solution {

    void dfs(int row,int column,int[][] grid,int[][] visited){
        visited[row][column] = 1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        for(int i=0;i<4;i++){
            int newrow = row + delrow[i];
            int newcol = column + delcol[i];
            if(newrow>=0 && newrow<grid.length && newcol>=0 && newcol<grid[0].length && visited[newrow][newcol]!=1 && grid[newrow][newcol]==1){
                dfs(newrow,newcol,grid,visited);
            }
        }
    }

    public int numEnclaves(int[][] grid) {
        int[][] visited = new int[grid.length][grid[0].length];
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
                visited[i][j] = 0;
            }
        }
        for(int i=0;i<grid.length;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,visited);
            }
        }
        for(int i=0;i<grid.length;i++){
            if(grid[i][grid[0].length-1]==1){
                dfs(i,grid[0].length-1,grid,visited);
            }
        }
        for(int i=0;i<grid[0].length;i++){
            if(grid[0][i]==1) dfs(0,i,grid,visited);
        }
        for(int i=0;i<grid[0].length;i++){
            if(grid[grid.length-1][i]==1) dfs(grid.length-1,i,grid,visited);
        }
        int count = 0;
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
                if(visited[i][j]==0 && grid[i][j]==1) count++;
            }
        }
        return count;
    }
}