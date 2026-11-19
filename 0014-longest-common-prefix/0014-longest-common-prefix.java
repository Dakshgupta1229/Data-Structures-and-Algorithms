class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        String str1 = strs[0];
        String str2 = strs[strs.length-1];
        String result = "";
        for(int i=0;i<Math.min(str1.length(),str2.length());i++){
            if(str1.charAt(i)==str2.charAt(i)){
                result = result + str1.charAt(i);
            }
            else break;
        }
        return result;
    }
}