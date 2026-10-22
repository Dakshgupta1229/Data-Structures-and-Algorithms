class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,(a,b) -> Integer.compare(a[0],b[0]));
        int start = intervals[0][0];
        int end = intervals[0][1];
        List<List<Integer>> list = new ArrayList<>();
        for(int i=1;i<intervals.length;i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(s<=end && e>=end){
                end = e;
            }
            else if(s<=end && e<=end) continue;
            else{
                List<Integer> list1 = new ArrayList<>();
                list1.add(start);
                list1.add(end);
                start = s;
                end = e;
                list.add(list1);
            }
        }
        List<Integer> list1 = new ArrayList<>();
        list1.add(start);
        list1.add(end);
        list.add(list1);
        int n = list.size();
        int[][] arr = new int[n][2];
        for(int i=0;i<arr.length;i++){
            List<Integer> list2 = list.get(i);
            arr[i][0] = list2.get(0);
            arr[i][1] = list2.get(1);
        }
        return arr;
    }
}