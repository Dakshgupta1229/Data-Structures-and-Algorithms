class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();
        for(int i=0;i<numRows;i++){
            int current = 1;
            List<Integer> list2 = new ArrayList<>();
            for(int j=0;j<=i;j++){
                list2.add(current);
                current = current * (i-j)/(j+1);
            }
            list.add(list2);
        }
        return list;
    }
}