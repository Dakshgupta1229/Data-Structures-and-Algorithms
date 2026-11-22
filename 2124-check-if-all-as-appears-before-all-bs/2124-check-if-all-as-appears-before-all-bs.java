class Solution {
    public boolean checkString(String s) {
        StringBuilder str = new StringBuilder(s);
        String ss = str.toString();
        char[] arr = ss.toCharArray();
        Arrays.sort(arr);
        String str2 = new String(arr);
        if(str2.equals(s)) return true;
        return false;
    }
}