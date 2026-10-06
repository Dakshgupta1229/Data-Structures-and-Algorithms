class Solution {
    public int maxVowels(String s, int k) {
        int max_count = 0;
        int count = 0;
        for(int i=0;i<k;i++){
            if(s.charAt(i)=='a' || s.charAt(i)=='e' || s.charAt(i)=='i' || s.charAt(i)=='o' || s.charAt(i)=='u') count++;
        }
        if(max_count<count) max_count = count;
        for(int i=1;i<=s.length()-k;i++){
            if(s.charAt(i-1)=='a' || s.charAt(i-1)=='e' || s.charAt(i-1)=='i' || s.charAt(i-1)=='o' || s.charAt(i-1)=='u') count--;
            if(s.charAt(i+k-1)=='a' || s.charAt(i+k-1)=='e' || s.charAt(i+k-1)=='i' || s.charAt(i+k-1)=='o' || s.charAt(i+k-1)=='u') count++;
            if(max_count<count) max_count = count;
        }
        return max_count;
    }
}