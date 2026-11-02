class Pair{
    int first;
    int second;
    Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
}


class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int old_color = image[sr][sc];
        int[][] visited = new int[image.length][image[0].length];
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
                visited[i][j] = 0;
            }
        }
        Queue<Pair> q = new LinkedList<Pair>();
        q.offer(new Pair(sr,sc));
        visited[sr][sc] = 1;
        while(q.size()>0){
            int row = q.peek().first;
            int column = q.peek().second;
            q.poll();
            image[row][column] = color;
            int[] delrow = {-1,0,1,0};
            int[] delcol = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int newrow = row + delrow[i];
                int newcol = column + delcol[i];
                if(newrow>=0 && newrow<image.length && newcol>=0 && newcol<image[0].length && image[newrow][newcol]==old_color && visited[newrow][newcol]!=1){
                    visited[newrow][newcol] = 1;
                    q.offer(new Pair(newrow,newcol));
                }
            }
        }
        return image;
    }
}