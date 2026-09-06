class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()==1) return false;
        string original = s;
        s+=s;
        s.pop_back();
        string result = s.substr(1);
        for(int i=0;i<=result.size()-original.size();i++){
            string str = result.substr(i,original.size());
            if(str==original) return true;
        }
        return false;
    }
};