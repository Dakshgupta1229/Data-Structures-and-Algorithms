class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int count = 0;
        for(int i=0;i<s.size();i++){
            string str;
            int count_zero = 0;
            int count_one = 0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='0') count_zero++;
                else count_one++;
                if(count_zero<=k || count_one<=k) count++;
                else break;
            }
        }
        return count;
    }
};