class Solution {
    public int numberOfSubstrings(String s) {
        int sum = 0;
        int first = -1;
        int second = -1;
        int third = -1;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='a') first = i;
            else if(s.charAt(i)=='b') second = i;
            else third = i;
            if(first!=-1 && second!=-1 && third!=-1){
                int min_ele = Math.min(first,Math.min(second,third));
                sum = sum + min_ele + 1;
            }
        }
        return sum;
    }
}