class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int low = 0;
        int high = mat[0].length-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int max_ele = Integer.MIN_VALUE;
            int r = -1;
            int c = -1;
            for(int i=0;i<mat.length;i++){
                if(max_ele<mat[i][mid]){
                    max_ele = mat[i][mid];
                    r = i;
                    c = mid;
                }
            }
            int left = -1;
            int right = -1;
            if(c+1<mat[0].length) right = mat[r][c+1];
            if(c-1>=0) left = mat[r][c-1];
            if(max_ele>left && max_ele>right){
                return new int[]{r,c};
            }
            else if(left>=max_ele) high = mid - 1;
            else low = mid + 1;
        }
        return new int[]{-1,-1};
    }
}