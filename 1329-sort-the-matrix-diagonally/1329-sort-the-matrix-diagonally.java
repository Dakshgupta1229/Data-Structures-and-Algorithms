class Solution {
    public int[][] diagonalSort(int[][] mat) {
        Map<Integer,List<Integer>> map = new HashMap<>();
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[i].length;j++){
                map.computeIfAbsent(i-j,k -> new ArrayList<>()).add(mat[i][j]);
            }
        }
        for(Integer p:map.keySet()){
            Collections.sort(map.get(p));
        }
        for(int i=mat.length-1;i>=0;i--){
            for(int j=mat[i].length-1;j>=0;j--){
                List<Integer> list = map.get(i-j);
                mat[i][j] = list.get(list.size()-1);
                list.remove(list.size()-1);
            }
        }
        return mat;
    }
}