class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        if(ops.length==0) return m*n;
        int row = Integer.MAX_VALUE;
        int column = Integer.MAX_VALUE;
        for(int i=0;i<ops.length;i++){
            int ele1 = ops[i][0];
            int ele2 = ops[i][1];
            row = Math.min(row,ele1);
            column = Math.min(column,ele2);
        }
        return row * column;
    }
}