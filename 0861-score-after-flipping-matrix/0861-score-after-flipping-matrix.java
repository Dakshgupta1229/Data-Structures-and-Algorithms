class Solution {
    public int matrixScore(int[][] grid) {
        for(int i=0;i<grid.length;i++){
            if(grid[i][0]==0){
                for(int j=0;j<grid[i].length;j++){
                    if(grid[i][j]==0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        for(int i=0;i<grid[0].length;i++){
            int count_zero = 0;
            int count_one = 0;
            for(int j=0;j<grid.length;j++){
                if(grid[j][i]==0) count_zero++;
                else count_one++;
            }
            if(count_zero>count_one){
                for(int j=0;j<grid.length;j++){
                    if(grid[j][i]==0) grid[j][i] = 1;
                    else grid[j][i] = 0;
                }
            }
        }
        int sum = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=1;j<grid[i].length;j++){
                grid[i][j] = 2 * grid[i][j-1] + grid[i][j];
            }
            sum = sum + grid[i][grid[i].length-1];
        }

        return sum;
    }
}