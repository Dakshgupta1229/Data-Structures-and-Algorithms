class Solution {
    public int maxVowels(String s, int k) {
        StringBuilder str = new StringBuilder(s);
        int max_count = 0;
        int count = 0;
        for(int i=0;i<k;i++){
            if(str.charAt(i)=='a' || str.charAt(i)=='e' || str.charAt(i)=='i' || str.charAt(i)=='o' || str.charAt(i)=='u'){
                count++;
            }
        }
        if(max_count<count) max_count = count;
        for(int i=1;i<=str.length()-k;i++){
            if(str.charAt(i-1)=='a' || str.charAt(i-1)=='e' || str.charAt(i-1)=='i' || str.charAt(i-1)=='o' || str.charAt(i-1)=='u'){
                count--;
            }
            if(str.charAt(i+k-1)=='a' || str.charAt(i+k-1)=='e' || str.charAt(i+k-1)=='i' || str.charAt(i+k-1)=='o' || str.charAt(i+k-1)=='u'){
                count++;
            }
            if(max_count<count) max_count = count;
        }
        return max_count;
    }
}