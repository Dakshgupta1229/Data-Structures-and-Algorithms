class Pair{
    int first;
    int second;
    Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
}


class Solution {
    public int numEnclaves(int[][] grid) {
        int[][] visited = new int[grid.length][grid[0].length];
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
                visited[i][j] = 0;
            }
        }
        Queue<Pair> q = new LinkedList<Pair>();
        for(int i=0;i<grid.length;i++){
            if(grid[i][0]==1 && visited[i][0]!=1){
                q.offer(new Pair(i,0));
                visited[i][0] = 1;
            }
        }
        for(int i=0;i<grid.length;i++){
            if(grid[i][grid[0].length-1]==1 && visited[i][grid[0].length-1]!=1){
                q.offer(new Pair(i,grid[0].length-1));
                visited[i][grid[0].length-1] = 1;
            }
        }
        for(int i=0;i<grid[0].length;i++){
            if(grid[0][i]==1 && visited[0][i]!=1){
                q.offer(new Pair(0,i));
                visited[0][i] = 1;
            }
        }
        for(int i=0;i<grid[0].length;i++){
            if(grid[grid.length-1][i]==1 && visited[grid.length-1][i]!=1){
                q.offer(new Pair(grid.length-1,i));
                visited[grid.length-1][i] = 1;
            }
        }
        while(q.size()>0){
            int row = q.peek().first;
            int column = q.peek().second;
            q.poll();
            int[] delrow = {-1,0,1,0};
            int[] delcol = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int newrow = row + delrow[i];
                int newcol = column + delcol[i];
                if(newrow>=0 && newrow<grid.length && newcol>=0 && newcol<grid[0].length && grid[newrow][newcol]==1 && visited[newrow][newcol]!=1){
                    q.offer(new Pair(newrow,newcol));
                    visited[newrow][newcol] = 1;
                }
            }
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