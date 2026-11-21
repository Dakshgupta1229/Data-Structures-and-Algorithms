class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points,(a,b) -> Integer.compare(a[0],b[0]));
        int max_diff = Integer.MIN_VALUE;
        for(int i=1;i<points.length;i++){
            int ele = points[i][0];
            int prev = points[i-1][0];
            if(max_diff<(ele-prev)){
                max_diff = ele - prev;
            }
        }
        return max_diff;
    }
}