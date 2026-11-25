class Solution {
    public long minimumSteps(String s) {
        long count = 0;
        int i=0;
        int j=s.length()-1;
        while(i<j){
            char ch1 = s.charAt(i);
            char ch2 = s.charAt(j);
            if(ch1=='0') i++;
            else if(ch2=='1') j--;
            else{
                count = count + (long)(j-i);
                i++;
                j--;
            }
        }
        return count;
    }
}