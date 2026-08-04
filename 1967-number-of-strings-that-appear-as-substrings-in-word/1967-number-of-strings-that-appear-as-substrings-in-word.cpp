class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        set<string> s;
        int count = 0;
        for(int i=0;i<word.size();i++){
            string str;
            for(int j=i;j<word.size();j++){
                str = str + word[j];
                s.insert(str);
            }
        }
        for(int i=0;i<patterns.size();i++){
            if(s.find(patterns[i])!=s.end()) count++;
        }
        return count;
    }
};