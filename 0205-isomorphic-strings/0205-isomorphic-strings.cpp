class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> v1(256,1000);
        vector<int> v2(256,1000);
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            int index = (int)s[i];
            if(v1[index]==1000){
                v1[index] = s[i] - t[i];
            }
            else if(v1[index]==(s[i]-t[i])) continue;
            else return false;
        }
        for(int i=0;i<t.size();i++){
            int index = (int)t[i];
            if(v2[index]==1000){
                v2[index] = t[i] - s[i];
            }
            else if(v2[index]==(t[i]-s[i])) continue;
            else return false;
        }
        return true;
    }
};