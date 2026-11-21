class Solution {
    public int numberOfSubstrings(String s) {
        int i=0;
        int j=0;
        int count_a = 0;
        int count_b = 0;
        int count_c = 0;
        int sum = 0;
        while(j<s.length()){
            char ch = s.charAt(j);
            if(ch=='a') count_a++;
            else if(ch=='b') count_b++;
            else count_c++;
            while(count_a>=1 && count_b>=1 && count_c>=1 && i<s.length()){
                sum = sum + (s.length()-j);
                char ch2 = s.charAt(i);
                if(ch2=='a') count_a--;
                else if(ch2=='b') count_b--;
                else count_c--;
                i++;
            }
            j++;
        }
        return sum;
    }
}