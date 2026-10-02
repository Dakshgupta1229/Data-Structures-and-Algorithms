class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();
        for(int i=0;i<numRows;i++){
            List<Integer> l = new ArrayList<>();
            int current = 1;
            l.add(current);
            for(int j=0;j<i;j++){
                current = current * (i-j)/(j+1);
                l.add(current);
            }
            list.add(l);
        }
        return list;
    }
}