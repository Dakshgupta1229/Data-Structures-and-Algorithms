class Solution {
public:
    int maxVowels(string s, int k) {
        int count_vowels = 0;
        int window_size = s.size()-k;
        int max_len = 0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                count_vowels++;
            }
        }
        if(max_len<count_vowels) max_len = count_vowels;
        for(int i=1;i<=window_size;i++){
            if(s[i-1]=='a' || s[i-1]=='e' || s[i-1]=='i' || s[i-1]=='o' || s[i-1]=='u') count_vowels--;
            if(s[i+k-1]=='a' || s[i+k-1]=='e' || s[i+k-1]=='i' || s[i+k-1]=='o' || s[i+k-1]=='u') count_vowels++;
            if(max_len<count_vowels) max_len = count_vowels;
        }
        return max_len;
    }
};