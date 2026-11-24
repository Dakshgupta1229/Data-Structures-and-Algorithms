class Pair{
    int first;
    int second;
    Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
}


class Solution {
    void bfs(int row,int column,int[][] image,int col,int[][] visited,int color){
        visited[row][column] = 1;
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(row,column));
        while(q.size()>0){
            int r1 = q.peek().first;
            int r2 = q.peek().second;
            image[r1][r2] = color;
            q.poll();
            int[] delrow = {-1,0,1,0};
            int[] delcolumn = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int new_row = r1 + delrow[i];
                int new_column = r2 + delcolumn[i];
                if(new_row>=0 && new_row<image.length && new_column>=0 && new_column<image[0].length && image[new_row][new_column]==col && visited[new_row][new_column]!=1){
                    visited[new_row][new_column] = 1;
                    q.offer(new Pair(new_row,new_column));
                }
            }
        }

    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int[][] visited = new int[image.length][image[0].length];
        for(int i=0;i<image.length;i++){
            for(int j=0;j<image[i].length;j++){
                visited[i][j] = 0;
            }
        }
        int col = image[sr][sc];
        bfs(sr,sc,image,col,visited,color);
        return image;
    }
}