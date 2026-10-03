class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string str = "";
        for(int i=0;i<min(strs[0].size(),strs[strs.size()-1].size());i++){
            if(strs[0][i]==strs[strs.size()-1][i]) str = str + strs[0][i];
            else break;
        }
        return str;
    }
};