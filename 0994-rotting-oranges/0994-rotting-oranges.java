class Pair{
    int first;
    int second;
    Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
};


class Solution {
    public int orangesRotting(int[][] grid) {
        int[][] visited = new int[grid.length][grid[0].length];
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
                visited[i][j] = 0;
            }
        }
        Queue<Pair> q = new LinkedList<Pair>();
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]==2) q.offer(new Pair(i,j));
            }
        }
        int count = 0;
        while(q.size()>0){
            boolean flag = false;
            int n = q.size();
            while(true){
                if(n==0) break;
                n--;
                int row = q.peek().first;
                int column = q.peek().second;
                q.poll();
                int delrow[] = {-1,0,1,0};
                int delcol[] = {0,-1,0,1};
                for(int i=0;i<4;i++){
                    int newrow = row + delrow[i];
                    int newcol = column + delcol[i];
                    if(newrow>=0 && newrow<grid.length && newcol>=0 && newcol<grid[0].length && grid[newrow][newcol]==1 && visited[newrow][newcol]!=1){
                        grid[newrow][newcol]  = 2;
                        visited[newrow][newcol] = 1;
                        q.offer(new Pair(newrow,newcol));
                        flag = true;
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