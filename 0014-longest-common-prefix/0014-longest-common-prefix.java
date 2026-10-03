class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        StringBuilder str = new StringBuilder();
        int n1 = strs[0].length();
        int n2 = strs[strs.length-1].length();
        String str1 = strs[0];
        String str2 = strs[strs.length-1];
        for(int i=0;i<Math.min(n1,n2);i++){
            if(str1.charAt(i)==str2.charAt(i)){
                str.append(str1.charAt(i));
            }
            else break;
        }
        return str.toString();
    }
}