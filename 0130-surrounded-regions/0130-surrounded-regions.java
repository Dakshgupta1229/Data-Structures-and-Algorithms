class Solution {

    void dfs(int row,int column,char[][] board,int[][] visited){
        visited[row][column] = 1;
        int[] delrow = {-1,0,1,0};
        int[] delcol = {0,-1,0,1};
        for(int i=0;i<4;i++){
            int newrow = row + delrow[i];
            int newcol = column + delcol[i];
            if(newrow>=0 && newrow<board.length && newcol>=0 && newcol<board[0].length && visited[newrow][newcol]!=1 && board[newrow][newcol]=='O'){
                dfs(newrow,newcol,board,visited);
            }
        }
    }

    public void solve(char[][] board) {
        int[][] visited = new int[board.length][board[0].length];
        for(int i=0;i<board.length;i++){
            if(board[i][0]=='O') dfs(i,0,board,visited);
        }
        for(int i=0;i<board.length;i++){
            if(board[i][board[0].length-1]=='O') dfs(i,board[0].length-1,board,visited);
        }
        for(int i=0;i<board[0].length;i++){
            if(board[0][i]=='O') dfs(0,i,board,visited);
        }
        for(int i=0;i<board[0].length;i++){
            if(board[board.length-1][i]=='O') dfs(board.length-1,i,board,visited);
        }
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
                if(visited[i][j]==0 && board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
}