class Solution {
public:
    int countValidPrefixes(string s) {
        int count_zero = 0;
        int count_one = 0;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') count_one++;
            if(s[i]=='0') count_zero++;
            if(abs(count_zero - count_one)<=1) count++;
        }
        return count;
    }
};