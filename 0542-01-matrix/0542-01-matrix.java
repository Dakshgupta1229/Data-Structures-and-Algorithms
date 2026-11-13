class Pair{
    int first;
    int second;
    int third;
    Pair(int first,int second,int third){
        this.first = first;
        this.second = second;
        this.third = third;
    }
}


class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int[][] visited = new int[mat.length][mat[0].length];
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
                visited[i][j] = 0;
            }
        }
        int[][] distance = new int[mat.length][mat[0].length];
        Queue<Pair> q = new LinkedList<Pair>();
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[i].length;j++){
                if(mat[i][j]==0){
                    q.offer(new Pair(i,j,0));
                    visited[i][j] = 1;
                }
            }
        }
        while(q.size()>0){
            int row = q.peek().first;
            int column = q.peek().second;
            int dist = q.peek().third;
            distance[row][column] = dist;
            q.poll();
            int[] delrow = {-1,0,1,0};
            int[] delcol = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int newrow = row + delrow[i];
                int newcol = column + delcol[i];
                if(newrow>=0 && newcol>=0 && newrow<mat.length && newcol<mat[0].length && visited[newrow][newcol]!=1){
                    q.offer(new Pair(newrow,newcol,dist+1));
                    visited[newrow][newcol] = 1;
                }
            }
        }
        return distance;
    }
}