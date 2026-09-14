class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i++){
            int count = s.size()-i;
            if(count>=2*k){
                reverse(s.begin()+i,s.begin()+i+k);
                i+=2*k-1;
            }
            else if(count>=k){
                reverse(s.begin()+i,s.begin()+i+k);
                break;
            }
            else{
                reverse(s.begin()+i,s.end());
                break;
            }
        }
        return s;
    }
};