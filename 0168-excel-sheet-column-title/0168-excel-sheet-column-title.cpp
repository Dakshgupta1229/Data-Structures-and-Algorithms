class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str;
        while(columnNumber>0){
            columnNumber--;
            int n = columnNumber%26;
            str = str + (char)(n+65);
            columnNumber/=26;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};