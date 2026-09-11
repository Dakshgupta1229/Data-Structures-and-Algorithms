class Solution {
public:
    bool isPalindromic(string s) {
        string str;
        for(int i=0;i<s.size();i++){
            int num = (int)s[i];
            int count = 0;
            while(num!=0){
                char ch = (char)(num%2+48);
                str+=ch;
                num = num/2;
                count++;
            }
            while(count<8){
                str+='0';
                count++;
            }
        }
        string result = str;
        reverse(result.begin(),result.end());
        if(str==result) return true;
        return false;
    }
};