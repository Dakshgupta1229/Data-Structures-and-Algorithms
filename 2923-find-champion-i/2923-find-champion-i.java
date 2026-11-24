class Solution {
    public int findChampion(int[][] grid) {
        for(int i=0;i<grid.length;i++){
            boolean flag = true;
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]!=1 && i!=j){
                    flag = false;
                }
            }
            if(flag==true) return i;
        }
        return -1;
    }
}