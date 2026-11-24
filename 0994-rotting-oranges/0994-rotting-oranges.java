class Pair{
    int first;
    int second;
    Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public int orangesRotting(int[][] grid) {
        int[][] visited = new int[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                visited[i][j] = 0;
            }
        }
        Queue<Pair> q = new LinkedList<>();
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]==2){
                    visited[i][j] = 1;
                    q.offer(new Pair(i,j));
                }
            }
        }
        int count = 0;
        while(q.size()>0){
            int n = q.size();
            boolean flag = false;
            for(int i=0;i<n;i++){
                int r1 = q.peek().first;
                int r2 = q.peek().second;
                grid[r1][r2] = 2;
                q.poll();
                int[] delrow = {-1,0,1,0};
                int[] delcol = {0,-1,0,1};
                for(int j=0;j<4;j++){
                    int new_row = r1 + delrow[j];
                    int new_column = r2 + delcol[j];
                    if(new_row>=0 && new_row<grid.length && new_column>=0 && new_column<grid[0].length && grid[new_row][new_column]==1 && visited[new_row][new_column]!=1){
                        flag = true;
                        visited[new_row][new_column] = 1;
                        q.offer(new Pair(new_row,new_column));
                    }
                }
            }
            if(flag==true) count++;
        }
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return count;
    }
}