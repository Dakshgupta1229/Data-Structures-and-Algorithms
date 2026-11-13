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
        int[][] visited = new int[image.length][image[0].length];
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
                visited[i][j] = 0;
            }
        }
        Queue<Pair> q = new LinkedList<Pair>();
        int initial = image[sr][sc];
        q.offer(new Pair(sr,sc));
        visited[sr][sc] = 1;
        while(q.size()>0){
            int r = q.peek().first;
            int c = q.peek().second;
            image[r][c] = color;
            q.poll();
            if(r-1>=0 && c>=0 && image[r-1][c]==initial && visited[r-1][c]!=1){
                q.offer(new Pair(r-1,c));
                visited[r-1][c] = 1;
            }
            if(r>=0 && c-1>=0 && image[r][c-1]==initial && visited[r][c-1]!=1){
                q.offer(new Pair(r,c-1));
                visited[r][c-1] = 1;
            }
            if(r+1<image.length && c>=0 && image[r+1][c]==initial && visited[r+1][c]!=1){
                q.offer(new Pair(r+1,c));
                visited[r+1][c] = 1;
            }
            if(r>=0 && c+1<image[0].length && image[r][c+1]==initial && visited[r][c+1]!=1){
                q.offer(new Pair(r,c+1));
                visited[r][c+1] = 1;
            }
        }
        return image;
    }
}