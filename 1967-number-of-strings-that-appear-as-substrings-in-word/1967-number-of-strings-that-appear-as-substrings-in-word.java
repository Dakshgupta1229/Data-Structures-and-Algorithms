class Solution {
    public int numOfStrings(String[] patterns, String word) {
        Set<String> set = new HashSet<>();
        for(int i=0;i<word.length();i++){
            StringBuilder str = new StringBuilder();
            for(int j=i;j<word.length();j++){
                str.append(word.charAt(j));
                set.add(str.toString());
            }
        }
        int count = 0;
        for(int i=0;i<patterns.length;i++){
            if(set.contains(patterns[i])){
                count++;
            }
        }
        return count;
    }
}