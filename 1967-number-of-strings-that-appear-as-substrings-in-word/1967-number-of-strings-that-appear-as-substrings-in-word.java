class Solution {
    public int numOfStrings(String[] patterns, String word) {
        Set<String> set = new HashSet<>();
        for(int i=0;i<word.length();i++){
            String str = "";
            for(int j=i;j<word.length();j++){
                str = str + word.charAt(j);
                set.add(str);
            }
        }
        int count = 0;
        for(int i=0;i<patterns.length;i++){
            if(set.contains(patterns[i])) count++;
        }
        return count;
    }
}