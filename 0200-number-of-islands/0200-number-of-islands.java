class Pair{
    int first;
    int second;
    Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
}


class Solution {

    public void bfs(char[][] grid,int[][] visited,int row,int column){
        visited[row][column] = 1;
        Queue<Pair> q = new LinkedList<Pair>();
        q.offer(new Pair(row,column));
        while(q.size()>0){
            int r = q.peek().first;
            int c = q.peek().second;
            q.poll();
                if(r-1>=0 && c>=0 && grid[r-1][c]=='1' && visited[r-1][c]!=1){
                    q.offer(new Pair(r-1,c));
                    visited[r-1][c] = 1;
                }
                if(r>=0 && c-1>=0 && grid[r][c-1]=='1' && visited[r][c-1]!=1){
                    q.offer(new Pair(r,c-1));
                    visited[r][c-1] = 1;
                }
                if(r+1<grid.length && c>=0 && grid[r+1][c]=='1' && visited[r+1][c]!=1){
                    q.offer(new Pair(r+1,c));
                    visited[r+1][c] = 1;
                }
                if(row>=0 && c+1<grid[0].length && grid[r][c+1]=='1' && visited[r][c+1]!=1){
                    q.offer(new Pair(r,c+1));
                    visited[r][c+1] = 1;
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
                    bfs(grid,visited,i,j);
                }
            }
        }
        return count;
    }
}