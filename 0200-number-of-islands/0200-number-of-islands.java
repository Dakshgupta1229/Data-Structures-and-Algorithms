class Pair{
    int first;
    int second;
    Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
};

class Solution {

    void bfs(int row,int column,char[][] grid,int[][] visited){
        Queue<Pair> q = new LinkedList<Pair>();
        q.offer(new Pair(row,column));
        visited[row][column] = 1;
        while(q.size()>0){
            int r1 = q.peek().first;
            int c1 = q.peek().second;
            q.poll();
            int[] delrow = {-1,0,1,0};
            int[] delcol = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int row1 = r1 + delrow[i];
                int col1 = c1 + delcol[i];
                if(row1>=0 && row1<grid.length && col1>=0 && col1<grid[0].length && grid[row1][col1]=='1' && visited[row1][col1]!=1){
                    visited[row1][col1] = 1;
                    q.offer(new Pair(row1,col1));
                }
            }
        }

    }

    public int numIslands(char[][] grid) {
        int[][] visited = new int[grid.length][grid[0].length];
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
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