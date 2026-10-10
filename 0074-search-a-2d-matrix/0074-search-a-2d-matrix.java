class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int low = 0;
        int high = matrix.length * matrix[0].length - 1;
        int column = matrix[0].length;
        while(low<=high){
            int mid = low + (high-low)/2;
            int row = mid/column;
            int col = mid%column;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
}