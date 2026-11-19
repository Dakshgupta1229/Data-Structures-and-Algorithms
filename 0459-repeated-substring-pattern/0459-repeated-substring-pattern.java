class Solution {
    public boolean repeatedSubstringPattern(String s) {
        StringBuilder str = new StringBuilder();
        str.append(s);
        str.append(s);
        str.deleteCharAt(0);
        str.deleteCharAt(str.length()-1);
        for(int i=0;i<=str.length()-s.length();i++){
            String str1 = str.substring(i,i+s.length());
            if(str1.equals(s)) return true;
        }
        return false;
    }
}