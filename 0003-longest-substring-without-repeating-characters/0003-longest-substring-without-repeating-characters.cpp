class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int max_length = 0;
        int i=0;
        int j=0;
        while(i<s.size()){
            if(m.find(s[i])==m.end()){
                m[s[i]] = i;
            }
            else{
                if(max_length<(i-j)) max_length = i-j;
                if(j<m[s[i]]+1) j = m[s[i]]+1;
                m[s[i]] = i;
            }
            i++;
        }
        if(max_length<(i-j)) max_length = (i-j);
        return max_length;
    }
};