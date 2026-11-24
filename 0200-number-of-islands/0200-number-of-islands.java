class Pair{
    int first;
    int second;
    Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
}
class Solution {

    void bfs(int row,int column,char[][] grid,int[][] visited){
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(row,column));
        visited[row][column] = 1;
        while(q.size()>0){
            int r1 = q.peek().first;
            int r2 = q.peek().second;
            q.poll();
            int[] delrow = {-1,0,1,0};
            int[] delcol = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int new_row = r1 + delrow[i];
                int new_col = r2 + delcol[i];
                if(new_row>=0 && new_row<visited.length && new_col>=0 && new_col<visited[0].length && grid[new_row][new_col]=='1' && visited[new_row][new_col]!=1){
                    visited[new_row][new_col] = 1;
                    q.offer(new Pair(new_row,new_col));
                }
            }
        }

    }

    public int numIslands(char[][] grid) {
        int[][] visited = new int[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                visited[i][j] = 0;
            }
        }
        int count = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]=='1' && visited[i][j]!=1){
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
}