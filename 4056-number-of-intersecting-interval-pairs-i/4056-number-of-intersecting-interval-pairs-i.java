class Solution {
    public int countIntersectingIntervals(int[][] intervals) {
        Arrays.sort(intervals,(a,b) -> Integer.compare(a[0],b[0]));
        int count = 0;
        for(int i=0;i<intervals.length;i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            for(int j=i+1;j<intervals.length;j++){
                int start = intervals[j][0];
                int end = intervals[j][1];
                if(start<=e) count++;
                else break;
            }
        }
        return count;
    }
}