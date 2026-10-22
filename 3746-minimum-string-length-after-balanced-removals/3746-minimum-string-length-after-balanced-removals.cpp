class Solution {
public:
    int minLengthAfterRemovals(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int count1 = 0;
        int count2 = 0;
        if(m.find('a')!=m.end()) count1 = m['a'];
        if(m.find('b')!=m.end()) count2 = m['b'];
        return abs(count1 - count2);
    }
};