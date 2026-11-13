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
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
                visited[i][j] = 0;
            }
        }
        Queue<Pair> q = new LinkedList<Pair>();
        int count = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==2){
                    q.offer(new Pair(i,j));
                    visited[i][j] = 1;
                }
            }
        }
        while(true){
            int n = q.size();
            if(n==0) break;
            boolean flag = false;
            while(n>0){
                int r = q.peek().first;
                int c = q.peek().second;
                grid[r][c] = 0;
                q.poll();
                if(r-1>=0 && c>=0 && grid[r-1][c]==1 && visited[r-1][c]!=1){
                    q.offer(new Pair(r-1,c));
                    visited[r-1][c] = 1;
                    flag = true;
                }
                if(r>=0 && c-1>=0 && grid[r][c-1]==1 && visited[r][c-1]!=1){
                    q.offer(new Pair(r,c-1));
                    visited[r][c-1] = 1;
                    flag = true;
                }
                if(r+1<grid.length && c>=0 && grid[r+1][c]==1 && visited[r+1][c]!=1){
                    q.offer(new Pair(r+1,c));
                    visited[r+1][c] = 1;
                    flag = true;
                }
                if(r>=0 && c+1<grid[0].length && grid[r][c+1]==1 && visited[r][c+1]!=1){
                    q.offer(new Pair(r,c+1));
                    visited[r][c+1] = 1;
                    flag = true;
                }
                n--;
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