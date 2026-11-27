class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();
        for(int i=0;i<numRows;i++){
            list.add(new ArrayList<>());
        }
        for(int i=0;i<numRows;i++){
            int current = 1;
            for(int j=0;j<=i;j++){
                list.get(i).add(current);
                current = current * (i-j)/(j+1);
            }
        }
        return list;
    }
}