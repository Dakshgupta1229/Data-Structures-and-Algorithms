class Solution {
    public void rotate(int[][] matrix) {
        for(int i=0;i<matrix.length;i++){
            for(int j=i;j<matrix[i].length;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i=0;i<matrix.length;i++){
            int i1 = 0;
            int j1 = matrix.length-1;
            while(i1<j1){
                int temp = matrix[i][i1];
                matrix[i][i1] = matrix[i][j1];
                matrix[i][j1] = temp;
                i1++;
                j1--;
            }
        }
    }
}