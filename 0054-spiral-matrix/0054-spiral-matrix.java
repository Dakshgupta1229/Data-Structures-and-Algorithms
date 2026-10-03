class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList();
        int min_row = 0;
        int max_row = matrix.length - 1;
        int min_column = 0;
        int max_column = matrix[0].length - 1;
        while(min_row<=max_row && min_column<=max_column){
            for(int i=min_column;i<=max_column;i++){
                list.add(matrix[min_row][i]);
            }
            min_row++;
            if(min_row>max_row || min_column>max_column) break;
            for(int i=min_row;i<=max_row;i++){
                list.add(matrix[i][max_column]);
            }
            max_column--;
            if(min_row>max_row || min_column>max_column) break;
            for(int i=max_column;i>=min_column;i--){
                list.add(matrix[max_row][i]);
            }
            max_row--;
            if(min_row>max_row || min_column>max_column) break;
            for(int i=max_row;i>=min_row;i--){
                list.add(matrix[i][min_column]);
            }
            min_column++;
        }
        return list;
    }
}