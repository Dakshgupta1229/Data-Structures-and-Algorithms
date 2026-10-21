class Solution {
public:
    int numberOfSubstrings(string s) {
        int first = -1;
        int second = -1;
        int third = -1;
        int sum = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') first = i;
            else if(s[i]=='b') second = i;
            else third = i;
            if(first!=-1 && second!=-1 && third!=-1){
                int min_ele = min(first,min(second,third));
                sum = sum + min_ele + 1;
            }
        }
        return sum;
    }
};