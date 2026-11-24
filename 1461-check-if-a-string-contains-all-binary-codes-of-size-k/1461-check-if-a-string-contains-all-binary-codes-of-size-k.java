class Solution {
    public boolean hasAllCodes(String s, int k) {
        Set<String> set = new HashSet<>();
        for(int i=0;i<=s.length()-k;i++){
            String result = "";
            for(int j=i;j<i+k;j++){
                result = result + s.charAt(j);
            }
            set.add(result);
        }
        if(set.size()==(int)Math.pow(2,k)) return true;
        return false;
    }
}