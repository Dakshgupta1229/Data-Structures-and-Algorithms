class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<=rowIndex;i++){
            long current = 1;
            for(int j=0;j<=i;j++){
                if(i==rowIndex) list.add((int)current);
                current = current * (long)(i-j)/(long)(j+1);
            }
        }
        return list;
    }
}