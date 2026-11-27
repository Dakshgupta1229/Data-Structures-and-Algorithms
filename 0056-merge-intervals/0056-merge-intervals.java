class Solution {
    public int[][] merge(int[][] intervals) {
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        Arrays.sort(intervals,(a,b) -> Integer.compare(a[0],b[0]));
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<intervals.length;i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(s<=end){
                end = Math.max(end,e);
            }
            else{
                ArrayList<Integer> list2 = new ArrayList<>();
                list2.add(start);
                list2.add(end);
                list.add(list2);
                start = s;
                end = e;
            }
        }
        ArrayList<Integer> list2 = new ArrayList<>();
        list2.add(start);
        list2.add(end);
        list.add(list2);
        int[][] result = new int[list.size()][2];
        for(int i=0;i<list.size();i++){
            ArrayList<Integer> list3 = list.get(i);
            for(int j=0;j<list3.size();j++){
                result[i][j] = list3.get(j);
            }
        }
        return result;
    }
}