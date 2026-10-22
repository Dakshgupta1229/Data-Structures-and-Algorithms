class Solution {
public:
    int partitionString(string s) {
        set<char> se;
        int count = 0;
        for(int i=0;i<s.size();i++){
            int size1 = se.size();
            se.insert(s[i]);
            int size2 = se.size();
            if(size1==size2){
                count++;
                se.clear();
                se.insert(s[i]);
            }
        }
        if(se.size()!=0) count++;
        return count;
    }
};