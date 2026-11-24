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
        Queue<Pair> q = new LinkedList<>();
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[i].length;j++){
                if(mat[i][j]==0){
                    visited[i][j] = 1;
                    q.offer(new Pair(i,j,0));
                }
            }
        }
        while(q.size()>0){
            int r = q.peek().first;
            int c = q.peek().second;
            int dist = q.peek().third;
            distance[r][c] = dist;
            q.poll();
            int[] delrow = {-1,0,1,0};
            int[] delcol = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int new_row = r + delrow[i];
                int new_column = c + delcol[i];
                if(new_row>=0 && new_row<mat.length && new_column>=0 && new_column<mat[0].length && visited[new_row][new_column]!=1){
                    visited[new_row][new_column] = 1;
                    q.offer(new Pair(new_row,new_column,dist+1));
                }
            }
        }
        return distance;
    }
}