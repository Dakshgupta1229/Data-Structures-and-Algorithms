class Solution {
    public int partitionString(String s) {
        Set<Character> set = new HashSet<>();
        int count = 0;
        for(int i=0;i<s.length();i++){
            int size1 = set.size();
            set.add(s.charAt(i));
            int size2 = set.size();
            if(size1==size2){
                count++;
                set.clear();
                set.add(s.charAt(i));
            }
        }
        if(set.size()!=0) count++;
        return count;
    }
}