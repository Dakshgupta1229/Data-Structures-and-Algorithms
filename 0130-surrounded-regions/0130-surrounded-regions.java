class Solution {

    void dfs(int row,int column,char[][] board,int[][] visited){
        visited[row][column] = 1;
        int[] delrow = {-1,0,1,0};
        int[] delcol = {0,-1,0,1};
        for(int i=0;i<4;i++){
            int new_row = row + delrow[i];
            int new_column = column + delcol[i];
            if(new_row>=0 && new_row<board.length && new_column>=0 && new_column<board[0].length && visited[new_row][new_column]!=1 && board[new_row][new_column]=='O'){
                dfs(new_row,new_column,board,visited);
            }
        }
    }

    public void solve(char[][] board) {
        int[][] visited = new int[board.length][board[0].length];
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
                visited[i][j] = 0;
            }
        }
        for(int i=0;i<board.length;i++){
            if(board[i][0]=='O' && visited[i][0]!=1) dfs(i,0,board,visited);
        }
        for(int i=0;i<board.length;i++){
            if(board[i][board[0].length-1]=='O' && visited[i][board[0].length-1]!=1) dfs(i,board[0].length-1,board,visited);
        }
        for(int i=0;i<board[0].length;i++){
            if(board[0][i]=='O' && visited[0][i]!=1){
                dfs(0,i,board,visited);
            }
        }
        for(int i=0;i<board[0].length;i++){
            if(board[board.length-1][i]=='O' && visited[board.length-1][i]!=1){
                dfs(board.length-1,i,board,visited);
            }
        }
        for(int i=0;i<visited.length;i++){
            for(int j=0;j<visited[i].length;j++){
                if(visited[i][j]!=1 && board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
}