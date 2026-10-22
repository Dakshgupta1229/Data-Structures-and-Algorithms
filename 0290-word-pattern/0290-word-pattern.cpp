class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        stringstream ss(s);
        string temp;
        while(ss>>temp){
            v.push_back(temp);
        }
        if(pattern.size()!=v.size()) return false;
        map<char,string> m;
        for(int i=0;i<pattern.size();i++){
            if(m.find(pattern[i])==m.end()){
                m[pattern[i]] = v[i];
            }
            else{
                if(m[pattern[i]]==v[i]) continue;
                else return false;
            }
        }
        map<string,char> m1;
        for(int i=0;i<v.size();i++){
            if(m1.find(v[i])==m1.end()){
                m1[v[i]] = pattern[i];
            }
            else{
                if(m1[v[i]]==pattern[i]) continue;
                else return false;
            }
        }
        return true;
    }
};