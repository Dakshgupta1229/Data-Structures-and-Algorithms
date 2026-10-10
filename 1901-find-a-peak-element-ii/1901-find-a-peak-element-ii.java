class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int low = 0;
        int high = mat[0].length-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int max_ele = Integer.MIN_VALUE;
            int idx = -1;
            for(int i=0;i<mat.length;i++){
                if(max_ele<mat[i][mid]){
                    max_ele = mat[i][mid];
                    idx = i;
                }
            }
            if(mid-1>=0 && mat[idx][mid-1]>=max_ele) high = mid - 1;
            else if(mid+1<mat[0].length && mat[idx][mid+1]>=max_ele) low = mid + 1;
            else return new int[]{idx,mid};
        }
        return new int[]{-1,-1};
    }
}